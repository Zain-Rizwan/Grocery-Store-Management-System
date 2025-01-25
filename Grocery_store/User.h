#pragma once

using namespace std;

class user {
public:
	char name[10];
	char password[10];
	char CNIC[15];
	char gender;
	char address[20];
	int phone;
	char location[10];
	char* getname();
	char* getCNIC();
	char* getPassword();
	char getGender();
	char* getAddress();
	int getPhone();

	void login();
	void login(int);
	void login(int, int);
	void registeration();
	void registeration(int);
	void registeration(int, int);
	void insertOBJ(user);

	bool checkCustomer(user);
	void insertCustomer(user);
	bool checkCustomerLogin(user);

	void insertManager(user);
	bool checkManager(user);
	bool checkManagerLogin(user);
};

