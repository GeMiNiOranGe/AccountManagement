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
* [Code showcase](#Code-showcase)
	* [Declaring Classes](#Declaring-Classes)
	* [Main functions](#Main-functions)

## Project content
Build an employee management app with 2 types of users: administrator and employee. Users must log in to the system to use the features, the system can detect whether the logged in user is an administrator or an employee, The system can detect whether the logged in user is an administrator or an employee, and then go directly to the menu screen corresponding to each role.

**The application uses files to store administrator and employee data**
1. Administrators.txt: store a list of administrators (with at least 3 managers) including:
	* Username.
	* Password.
1. Employees.txt: store a list of employees including:
	* Username.
	* Password.
1. [username].txt: store information of each user including
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

## Code showcase
### Declaring Classes
Class `User` in [`User.hpp`](MainProject/User.hpp#L8)
```cpp
class User {
public:
	User(
		std::string _username = "", std::string _password = DEFAULT_PASSWORD, std::string _id = "",
		std::string _full_name = "", std::string _address = "",
		std::string _phone_number = "", std::string _email_address = ""
	);
	User(const User &);
	~User();

	std::string * get_properties();

	const std::string & get_username();
	const std::string & get_password();
	const std::string & get_id();
	const std::string & get_full_name();
	const std::string & get_address();
	const std::string & get_phone_number();
	const std::string & get_email_address();

	void set_username(const std::string &);
	void set_password(const std::string &);
	void set_id(const std::string &);
	void set_full_name(const std::string &);
	void set_address(const std::string &);
	void set_phone_number(const std::string &);
	void set_email_address(const std::string &);

private:
	std::string username;
	std::string password;
	std::string id;
	std::string full_name;
	std::string address;
	std::string phone_number;
	std::string email_address;
};
```
Class `Administrator` inherits class CUser in [`Administrator.hpp`](MainProject/Administrator.hpp#L8)
```cpp
class Administrator : public User {
public:
	Administrator(
		std::string _username = "", std::string _password = DEFAULT_PASSWORD, std::string _id = "",
		std::string _full_name = "", std::string _address = "",
		std::string _phone_number = "", std::string _email_address = ""
	);

	void add_employee(std::string _username);
	void erase_employee(std::string _username);
	void update_info_employee(std::string _username, std::string _info_updated, char _option);
};
```
Class `Employee` inherits class CUser in [`Employee.hpp`](MainProject/Employee.hpp#L10)
```cpp
class Employee : public User {
public:
	Employee(
		std::string _username = "", std::string _password = DEFAULT_PASSWORD, std::string _id = "",
		std::string _full_name = "", std::string _address = "",
		std::string _phone_number = "", std::string _email_address = ""
	);

	bool is_success_change_pass(
		std::string _username,
		std::string _current_password,
		std::string _new_password,
		std::string _confirm_new_password
	);
};
```

### Main functions
Some important functions for main processing in the source code and the definition of the methods of the classes

Important file path in [`Config.hpp`](MainProject/Config.hpp)
```cpp
const std::string ACCOUNTS_FILE = "Resources\\Accounts.txt";
const std::string USERS_INFO_FOLDER = "Resources\\UsersInfo\\";
const std::string DEFAULT_PASSWORD = "111111";
```
#### Function `add_employee`:
Source code function `add_employee` in [`Administrator.cpp`](MainProject/Administrator.cpp#L10)
```cpp
void Administrator::add_employee(std::string _username) {
	// Update file Accounts.txt
	std::ofstream account_list;
	account_list.open(ACCOUNTS_FILE, std::ios_base::app);
	account_list << "EM," << _username << ',' << DEFAULT_PASSWORD << std::endl;
	// Create a new file and add information to the newly created file
	std::ofstream fout = create_file(_username);
	console::read_info(*this);
	io::File::write_info_from(*this, fout);
	fout.close();
}
```
#### Function `erase_employee`:
Source code function `delete_account` in [`HandleMain.cpp`](MainProject/HandleMain.cpp#L19)
```cpp
void delete_account(std::string _username) {
	const std::string accounts = ACCOUNTS_FILE;
	std::string accounts_temp = accounts;
	User user;

	// Rename Accounts.txt into AccountsTemp.txt
	accounts_temp.insert(accounts_temp.size() - 4, "Temp");
	if (rename(accounts.c_str(), accounts_temp.c_str()) != 0) {
		std::cerr << "Error renaming file" << std::endl;
		return;
	}

	// Automatically create a new Accounts.txt
	std::ofstream fout(accounts);
	std::ifstream fin;
	// And open the file is renamed (AccountsTemp.txt)
	fin.open(accounts_temp.c_str());

	if (!fin.is_open() || !fout.is_open()) {
		std::cerr << "Failed to open files" << std::endl;
		return;
	}

	// Write from the file is renamed (AccountsTemp.txt) to Accounts.txt
	// And don't write the employee want to delete
	while (!fin.eof()) {
		io::File::read_account_from(fin, user);
		if (!user.get_username().empty() && user.get_username() != _username)
			io::File::write_account_from(user, fout);
	}
	fout.close();
	fin.close();
	if (remove(accounts_temp.c_str()) != 0) {
		std::cerr << "Failed to remove file" << std::endl;
		return;
	}
}
```
Source code function `delete_file` in [`HandleMain.cpp`](MainProject/HandleMain.cpp#L14)
```cpp
void delete_file(std::string _username) {
	std::string command = "del " + USERS_INFO_FOLDER + _username + ".txt";
	system(command.c_str());
}
```
Source code function `erase_employee` in [`Administrator.cpp`](MainProject/Administrator.cpp#L21)
```cpp
void Administrator::erase_employee(std::string _username) {
	delete_account(_username);
	delete_file(_username);
}
```
#### Function `update_info_employee`
Source code function `update_info_employee` in [`Administrator.cpp`](MainProject/Administrator.cpp#L25)
```cpp
void Administrator::update_info_employee(std::string _username, std::string _info_updated, char _option) {
	// Load infomation from _username file
	std::ifstream fin = open_file(_username);
	io::File::read_info_from(fin, *this);
	fin.close();
	// Re-open the _username file again
	std::ofstream fout;
	fout.open((USERS_INFO_FOLDER + _username + ".txt").c_str());
	// Change the data and overwrite the information from the userTemp
	if (_option == 49)
		User::set_full_name(_info_updated);
	if (_option == 50)
		User::set_address(_info_updated);
	if (_option == 51)
		User::set_phone_number(_info_updated);
	if (_option == 52)
		User::set_email_address(_info_updated);
	io::File::write_info_from(*this, fout);
	fout.close();
}
```
#### Function `show_info_accounts`
This code is the shortest I could write. Basically, this function will find the longest string size in each column and set it for each column cell in the table. Conclusion, it will respond to the longest string size.

Source code function `show_info_accounts` in [`UIHaveNoUX.cpp`](MainProject/UIHaveNoUX.cpp#L139)
```cpp
void show_info_accounts() {
	std::string titles[] = {
		"Id",
		"Username",
		"Password",
		"Full name",
		"Address",
		"Phone number",
		"Email address"
	};
	const int titles_size = sizeof(titles) / sizeof(titles[0]);
	std::vector<short> title_max_sizes;
	std::vector<std::pair<short, std::wstring>> vec_title_max_size_and_title;
	std::ifstream file_in;

	// Initialize each element in title_max_sizes with the string size of each element in titles
	for (auto & title : titles) title_max_sizes.push_back(static_cast<short>(title.size()));

	file_in.open(ACCOUNTS_FILE);

	while (!file_in.eof()) {
		User user;
		io::File::read_account_from(file_in, user);
		std::ifstream file_info = open_file(user.get_username());
		io::File::read_info_from(file_info, user);
		// Get all properties in class User
		// TODO: convert to vector
		std::string * ptr_user_properties = user.get_properties();

		// Find the maximum size of each table cell, horizontally
		if (user.get_username() != "")
			for (short i = 0; i < titles_size; i++)
				if (title_max_sizes[i] < ptr_user_properties[i].size())
					title_max_sizes[i] = static_cast<short>(ptr_user_properties[i].size());

		file_info.close();
	}

	// Reset file pointer
	file_in.clear();
	file_in.seekg(0, std::ios::beg);

	show_a_part_border(title_max_sizes, Position::FIRST);
	std::cout << std::endl;

	// Show titles
	for (short i = 0; i < titles_size; i++)
		vec_title_max_size_and_title.push_back(std::make_pair(title_max_sizes[i], Convert::to_wstring(titles[i])));
	show_info_account(vec_title_max_size_and_title, Color::LIGHT_YELLOW);
	std::cout << std::endl;

	// Show all account information
	while (!file_in.eof()) {
		User user;
		io::File::read_account_from(file_in, user);
		std::ifstream file_info = open_file(user.get_username());
		io::File::read_info_from(file_info, user);
		// Get all properties in class User
		std::string * ptr_user_properties = user.get_properties();

		std::vector<std::pair<short, std::wstring>> title_max_size_user_property;
		for (short i = 0; i < titles_size; i++)
			title_max_size_user_property.push_back(std::make_pair(title_max_sizes[i], Convert::to_wstring(ptr_user_properties[i])));

		// Show current account information
		if (user.get_username() != "") {
			show_a_part_border(title_max_sizes, Position::MIDDLE);
			std::cout << std::endl;

			show_info_account(title_max_size_user_property, Color::WHITE);
			std::cout << std::endl;
		}

		file_info.close();
	}

	show_a_part_border(title_max_sizes, Position::LAST);

	file_in.close();
}

```
#### Function `show_account_info`
This function simply reads the account information from the given [username].txt, and outputs it to the console.

Source code function `show_account_info` in [`HandleMain.cpp`](MainProject/HandleMain.cpp#L57)
```cpp
void show_account_info(std::string _username) {
	User user;
	std::ifstream fin = open_file(_username);
	io::File::read_info_from(fin, user);
	console::write_info(user);
	fin.close();
}
```
#### Function `is_success_change_pass`
Source code function `is_success_change_pass` in [`Employee.cpp`](MainProject/Employee.cpp#L10)
```cpp
bool Employee::is_success_change_pass(std::string _username, std::string _current_password, std::string _new_password, std::string _confirm_new_password) {
	bool is_successful = false;
	if (_current_password != _new_password && _new_password == _confirm_new_password) {
		const std::string accounts = ACCOUNTS_FILE;
		std::string accounts_temp = accounts;

		// Rename Accounts.txt into AccountsTemp.txt
		accounts_temp.insert(accounts_temp.size() - 4, "Temp");
		if (rename(accounts.c_str(), accounts_temp.c_str()) != 0) {
			std::cerr << "Error renaming file" << std::endl;
			return false;
		}

		// Automatically create a new Accounts.txt
		std::ofstream fout(accounts);
		std::ifstream fin;
		// And open the file is renamed (AccountsTemp.txt)
		fin.open(accounts_temp.c_str());

		if (!fin.is_open() || !fout.is_open()) {
			std::cerr << "Failed to open files" << std::endl;
			return false;
		}

		// Write from the file is renamed (AccountsTemp.txt) to Accounts.txt
		// And update password the account want to update
		while (!fin.eof()) {
			io::File::read_account_from(fin, *this);
			if (!User::get_username().empty()) {
				if (User::get_username() == _username && User::get_password() == _current_password) {
					User::set_password(_new_password);
					io::File::write_account_from(*this, fout);
					is_successful = true;
				}
				else
					io::File::write_account_from(*this, fout);
			}
		}

		fout.close();
		fin.close();
		if (remove(accounts_temp.c_str()) != 0) {
			std::cerr << "Failed to remove file" << std::endl;
			return false;
		}
	}
	return is_successful;
}
```
