# Employee Management Console application 
This is the first version of this app, i recommend you use branch UpdateToVS2019

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
Class CUser in `CUser.h`
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
Class CAdministrator inherits class CUser in CAdministrator.h
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
Class CEmployee inherits class CUser in CEmployee.h
```cpp
class CEmployee:
	public CUser {
public:
	CEmployee(string = "", string = "111111", string = "", string = "", string = "", string = "");

	bool isSuccessChangePass(string, string, string, string);
};
```
