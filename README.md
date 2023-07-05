# Employee Management Console application

## Table of Contents
* [Project content](#Project-content)
	* [Administrator features include](#Administrator-features-include)
		* [Add an employee account](#Add-an-employee-account)
		* [Delete an employee account](#Delete-an-employee-account)
		* [Find an employee account](#Find-an-employee-account)
		* [Update information an employee account](#Update-information-an-employee-account)
		* [Display all information of all employee accounts](#Display-all-information-of-all-employee-accounts)
	* [Employee features include](#Employee-features-include)
		* [View account information](#View-account-information)
		* [Change password](#Change-password)
	* [Other requirements](#Other-requirements)
* [Source code explanation](#Source-code-explanation)
	* [Declaring Classes](#Declaring-Classes)
	* [Main functions](#Main-functions)

## Project content
Build an employee management app with 2 types of users: administrator and employee. Users must log in to the system to use the features, the system can detect whether the logged in user is an administrator or an employee, The system can detect whether the logged in user is an administrator or an employee, and then go directly to the menu screen corresponding to each role.

**The application uses files to store administrator and employee data**
1. Administrators.txt: store a list of administrators (with at least 3 managers) including:
	* Username.
	* Password.
2. Employees.txt: store a list of employees including:
	* Username.
	* Password.
3. [username].txt: store information of each user including
	* Full name.
	* Address.
	* Phone number.
	* Email address.

### Administrator features include
* **After login**, the administrator is only allowed to access features such as:
	* Add an employee account.
	* Delete an employee account.
	* Find an employee account.
	* Update information an employee account.
	* Display all information of all employee accounts.
	* Exit the program or log out.

#### Add an employee account
* Add an new employee include: username, password, full name, address, phone number, email address.
	* *If the username is the same, do not add.*
	* *Default password is 111111.*
	* *If the addition is successful, update file Employees.txt (add the username and password to the file Employees.txt) and create a file [username].txt that stores the user's information including: full name, address, phone number and email address. **(one line for each information)***

#### Delete an employee account
* If the deletion is successful, update the file employee.txt (delete the username and password that need to be deleted in the employee.txt file) and delete the file [username].txt.

#### Find an employee account.
* Find and display employee information by username.

#### Update information an employee account.
* Update information full name, address, phone number, email address.
	* *Allow administrator to choose any information to update.*
	* *Update file information [username].txt.*

#### Display all information of all employee accounts.
* Display all information include: username, password, full name, address, phone number, email address.

### Employee features include
* If login wrong with 3 three times then exit.
* If it is the first time log in, the program will force you to change your password after successful login. Update file employee.txt.
* **After login**, the employee is only allowed to access features such as:
	* *View account information.*
	* *Change password.*

#### View account information.
* Displays the full name, address, phone number, and email address of the corresponding file [username].txt.

#### Change password.
* When user wants to change password on second login.
	* *Before entering a new password, you need to enter the password to confirm the account holder.*
	* *Enter 2 times for new password to confirm.*
	* *Update file employee.txt.*

### Other requirements
* The user can choose the options or end the program.
* In the event of an error, the system will notify the user of the error information, cancel the current function and allow the user to choose another function to execute or terminate the program.
* Encrypt password with * sign when logging in.
* Use color to design an easy-to-see interface.

## Source code explanation
### Declaring Classes
Class `CUser` in [`CUser.h`](Project2/CUser.h#L12)
```cpp
class CUser {
public:
	CUser(string = "", string = "111111", string = "", string = "", string = "", string = "");
	CUser(const CUser &);
	~CUser();

	const string& getUsername();
	const string& getPassword();
	const string& getFullName();
	const string& getAddress();
	const string& getPhoneNumber();
	const string& getEmailAddress();

	void setUsername(const string&);
	void setPassword(const string&);
	void setFullName(const string&);
	void setAddress(const string&);
	void setPhoneNumber(const string&);
	void setEmailAddress(const string&);

	void readAccount(ifstream&);
	void writeAccount(ofstream&);
	void readInfo(ifstream&);
	void writeInfo(ofstream&);

	void input();
	void output();
private:
	string strUsername;
	string strPassword;
	string strFullName;
	string strAddress;
	string strPhoneNumber;
	string strEmailAddress;
};
```
Class `CAdministrator` inherits class CUser in [`CAdministrator.h`](Project2/CAdministrator.h#L9)
```cpp
class CAdministrator:
	public CUser {
public:
	CAdministrator(string = "", string = "111111", string = "", string = "", string = "", string = "");

	void addEmployee(string);
	void eraseEmployee(string);
	void updateInfoEmployee(string, string, char);
	void showInfoAllEmployee();
};
```
Class `CEmployee` inherits class CUser in [`CEmployee.h`](Project2/CEmployee.h#L10)
```cpp
class CEmployee:
	public CUser {
public:
	CEmployee(string = "", string = "111111", string = "", string = "", string = "", string = "");

	bool isSuccessChangePass(string, string, string, string);
};
```

### Main functions
Some important functions for main processing in the source code and the definition of the methods of the classes

Important file path in [`Config.h`](Project2/Config.h)
```cpp
const string EMPLOYEES_FILE = "Resources\\Employees.txt";
const string ADMINISTRATOR_FILE = "Resources\\Admin.txt";
const string USER_INFO_FOLDER = "Resources\\UserInfo\\";
```
#### Function `addEmloyee`:
Step 1. create a new variable `fileUpdated` to open the list of employees in `EMPLOYEES_FILE` and add the latest employee name at the end of the file with the default password of "111111".

Step 2: create a new file [username].txt in `USER_INFO_FOLDER`.

Source code function `addEmployee` in [`CAdministrator.cpp`](Project2/CAdministrator.cpp#L8)
```cpp
void CAdministrator::addEmployee(string strUsername) {
	// Step 1
	ofstream fileUpdated;
	fileUpdated.open(EMPLOYEES_FILE, ios_base::app);
	fileUpdated << strUsername << "," << "111111" << endl;
	// Step 2
	ofstream fileOut = createFile(strUsername);
	input();
	writeInfo(fileOut);
	fileOut.close();
}
```
#### Function `eraseEmployee`:
Step 1: rename Employees.txt into EmployeesTemp.txt.

Step 2: create a new Employees.txt and open the file is renamed (EmployeesTemp.txt).

Step 3: write from the file is renamed (EmployeesTemp.txt) to Employees.txt and don't write the employee want to delete.

Step 4: delete the file is renamed (EmployeesTemp.txt).

Source code function `deleteAccount` in [`HandleMain.cpp`](Project2/HandleMain.cpp#L19)
```cpp
void deleteAccount(string strSourceFile, string strUsername) {
	CUser userTemp;
	//Step 1:
	string employeeFileRenamed = strSourceFile;
	rename(strSourceFile.c_str(), employeeFileRenamed.insert(employeeFileRenamed.size() - 4, "Temp").c_str());
	//Step 2:
	ofstream fileOut(strSourceFile);
	ifstream fileIn;
	fileIn.open(employeeFileRenamed.c_str());
	//Step 3:
	while (!fileIn.eof()) {
		userTemp.readAccount(fileIn);
		if (userTemp.getUsername() != strUsername && userTemp.getUsername() != "")
			userTemp.writeAccount(fileOut);
	}
	fileOut.close();
	fileIn.close();
	//Step 4:
	system(employeeFileRenamed.insert(0, "del ").c_str());
}
```
Source code function `deleteFile` in [`HandleMain.cpp`](Project2/HandleMain.cpp#L14)
```cpp
void deleteFile(string strUsernameFile) {
	string filePath = "del " + USER_INFO_FOLDER + strUsernameFile + ".txt";
	system(filePath.c_str());
}
```
Source code function `eraseEmployee` in [`CAdministrator.cpp`](Project2/CAdministrator.cpp#L19)
```cpp
void CAdministrator::eraseEmployee(string strUsername) {
	deleteAccount(EMPLOYEES_FILE, strUsername);
	deleteFile(strUsername);
}
```
#### Function `updateInfoEmployee`
Step 1: load infomation from sourceUserFile

Step 2: re-open the sourceUserFile again

Step 3: change the data and overwrite the information from the userTemp

Source code function `updateInfoEmployee` in [`CAdministrator.cpp`](Project2/CAdministrator.cpp#L26)
```cpp
void CAdministrator::updateInfoEmployee(string strSourceUserFile, string strInfoUpdated, char cOption) {
	//Step 1:
	ifstream fileIn = openFile(strSourceUserFile);
	readInfo(fileIn);
	fileIn.close();
	//Step 2:
	ofstream fileOut;
	fileOut.open((USER_INFO_FOLDER + strSourceUserFile + ".txt").c_str());
	//Step 3:
	if (cOption == 49)
		setFullName(strInfoUpdated);
	if (cOption == 50)
		setAddress(strInfoUpdated);
	if (cOption == 51)
		setPhoneNumber(strInfoUpdated);
	if (cOption == 52)
		setEmailAddress(strInfoUpdated);
	writeInfo(fileOut);
	fileOut.close();
}
```
#### Function `showInfoAllEmployee`
Step 1: load username and password into userTemp from file Employees.txt

Step 2: load information into userTemp from file [username].txt

Step 3: export information to console

Source code function `showInfoAllEmployee` in [`CAdministrator.cpp`](Project2/CAdministrator.cpp#L49)
```cpp
void CAdministrator::showInfoAllEmployee() {
	ifstream fileIn;
	fileIn.open(EMPLOYEES_FILE);
	showAnEmployeeInfoElement(9,"Ten tai khoan", "Ho va ten", "Dia chi", "So dien thoai", "Dia chi email", "| ");
	showAnEmployeeInfoElement(15,"-", "-", "-", "-", "-", "+-", '-');
	while (!fileIn.eof()) {
		//Step 1:
		readAccount(fileIn);
		//Step 2:
		ifstream fileUserInfoTemp = openFile(getUsername());
		readInfo(fileUserInfoTemp);
		//Step 3:
		if (getUsername() != "") {
			showAnEmployeeInfoElement(15, getUsername(), getFullName(), getAddress(), getPhoneNumber(), getEmailAddress(), "| ");
			showAnEmployeeInfoElement(15, "-", "-", "-", "-", "-", "+-", '-');
		}
		fileUserInfoTemp.close();
	}
	fileIn.close();
}
```
#### Function `showAccountInfo`
This function simply reads the account information from the given [username].txt, and outputs it to the console.

Source code function `showAccountInfo` in [`HandleMain.cpp`](Project2/HandleMain.cpp#L40)
```cpp
void showAccountInfo(string strUsername) {
	CUser userTemp;
	ifstream fileIn = openFile(strUsername);
	userTemp.readInfo(fileIn);
	userTemp.output();
	fileIn.close();
}
```
#### Function `isSuccessChangePass`
I dunno how to explain this source, because it still has bug =))))))) maybe, have fun

Source code function `isSuccessChangePass` in [`CEmployee.cpp`](Project2/CEmployee.cpp#L7)
```cpp
bool CEmployee::isSuccessChangePass(string strUsername, string strCurrentPass, string strNewPass, string strConfirmNewPass) {
	ifstream fileIn;
	fileIn.open(EMPLOYEES_FILE.c_str());
	while (!fileIn.eof()) {
		readAccount(fileIn);
		if (getUsername() == strUsername && getPassword() == strCurrentPass && strNewPass == strConfirmNewPass) {
			setPassword(strNewPass);
			fileIn.close();
			deleteAccount(EMPLOYEES_FILE, strUsername);
			ofstream fileOut;
			fileOut.open(EMPLOYEES_FILE.c_str(), ios_base::app);
			writeAccount(fileOut);
			fileOut.close();
			return true;
		}
	}
	fileIn.close();
	return false;
}
```
