#include <iostream>
#include "User.h"
#include "Admin.h"
#include "Manager.h"
#include "Customer.h"

#include <fstream>

using namespace std;

char* user::getname() {
	return name;
}
char* user::getCNIC() {
	return CNIC;
}
char* user::getPassword() {
	return password;
}
char user::getGender() {
	return gender;
}
char* user::getAddress() {
	return address;
}
int user::getPhone() {
	return phone;
}

bool user::checkManager(user z) {
	user temp;
	fstream myFile("Manager.bin", ios::in | ios::out | ios::binary);

	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (strcmp(temp.name, z.name) == 0) {
			return 0;
		}
	}
	myFile.close();
	return 1;
}

bool user::checkManagerLogin(user z) {
	user temp;
	fstream myFile("Manager.bin", ios::in | ios::out | ios::binary);

	while (myFile.read((char*)&temp, sizeof(temp))) {
		if ((strcmp(temp.name, z.name) == 0) && (strcmp(temp.password, z.password) == 0)) {
			return 1;
		}
			
	}
	myFile.close();
	return 0;
}

void user::insertManager(user z) {
	ofstream myFile("Manager.bin", ios::binary | ios::app);
	if (myFile.write((char*)&z, sizeof(z)))
		cout << "Object Successfully Inserted!" << endl;
	else
		cout << "Object Insertion Failed" << endl;
	myFile.close();
}

void user::insertOBJ(user z) {
	ofstream myFile("admin.bin", ios::binary | ios::app);
	if (myFile.write((char*)&z, sizeof(z)))
		cout << "Object Successfully Inserted!" << endl;
	else
		cout << "Object Insertion Failed" << endl;
	myFile.close();

}

bool user::checkCustomer(user z) {
	user temp;
	fstream myFile("Customer.bin", ios::in | ios::out | ios::binary);

	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (strcmp(temp.CNIC, z.CNIC) == 0) {
			return 0;
		}

	}
	myFile.close();

	return 1;
}
void user::insertCustomer(user z) {
	ofstream myFile("Customer.bin", ios::binary | ios::app);
	if (myFile.write((char*)&z, sizeof(z)))
		cout << "Customer Successfully Inserted!" << endl;
	else
		cout << "Customer Insertion Failed" << endl;
	myFile.close();
}
bool user::checkCustomerLogin(user z) {
	user temp;
	fstream myFile("Customer.bin", ios::in | ios::out | ios::binary);

	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (strcmp(temp.name, z.name) == 0) {
			if(strcmp(temp.password, z.password) == 0)
			return 1;
		}

	}
	myFile.close();

	return 0;


}

void user::login() {
	cout << "Enter User Name: ";
	cin >> name;
	cout << "Enter Password: ";
	cin >> password;
		admin temp;
		fstream myFile;
		myFile.open("admin.bin", ios::in | ios::binary);
		if (!myFile.is_open()) {
			cout << "zain" << endl;
			return;
		}
		while (!myFile.eof()) {
			myFile.read((char*)&temp, sizeof(temp));
			if ((strcmp(temp.name, name)==0)){
				if (strcmp(temp.password, password) == 0) {
					admin a;
					a.AdminMenu();
				}
				else {
					system("cls");
					cout << "Password wrong\nTry Again\n";
					user u;
					u.login();
				}
					
			}
			else {
				system("cls");
				cout << "User name wrong\nTry Again\n";
				user z;
				z.login();
			}
		}
		myFile.close();
}

void user::login(int a) {
	cout << "Enter User Name: ";
	cin >> name;
	cout << "Enter Password: ";
	cin >> password;
	if (checkManagerLogin(*this) == 1) {
		manager m;
		m.managerMenu();
	}
	else {
		system("cls");
		cout << "Wrong credentials Entered\nTry Again\n";
		login(1);
	}

}
void user::login(int a, int b) {
	cout << "Enter User Name: ";
	cin >> name;
	cout << "Enter Password: ";
	cin >> password;
	if (checkCustomerLogin(*this) == 0) {
		cout << "Invalid Credentials\Try Again\n\n";
		login(1, 1);
	}
	else {
		customer c;
		c.showShop();
		/*feedback f;
		f.showFeedBack();*/
	}
}

void user::registeration() {
	cout << "Admin Registeration called\n";
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter password: ";
	cin >> password;
	insertOBJ(*this);
	admin a;
	a.AdminMenu();

}
void user::registeration(int a) {
	char op;
	bool o=1;
	cout << "Manager Registeration called\n";
	cout << "Enter Manager Name: ";
	cin >> name;
	cout << "Enter Password: ";
	cin >> password;
	while (o) {
		cout << "Enter Location Of the Manager:\n1. Karachi\n2. Islamabad\n3. Lahore\nChoose: ";
		cin >> op;
		if (op == '1') {
			o = false;
			location[0] = 'K';
			location[1] = 'a';
			location[2] = 'r';
			location[3] = 'a';
			location[4] = 'c';
			location[5] = 'h';
			location[6] = 'i';
			location[7] = '\0';

			cout << location;

		}
		else if (op == '2') {
			o = false;
			location[0] = 'I';
			location[1] = 's';
			location[2] = 'l';
			location[3] = 'a';
			location[4] = 'm';
			location[5] = 'a';
			location[6] = 'b';
			location[7] = 'a';
			location[8] = 'd';
			location[9] = '\0';
			cout << location;

		}
		else if (op == '3') {
			o = false;
			location[0] = 'L';
			location[1] = 'a';
			location[2] = 'h';
			location[3] = 'o';
			location[4] = 'r';
			location[5] = 'e';
			location[6] = '\0';
			cout << location;
		}
		else {
			cout << "\nInvalid Option Choosed!\nTry Again\n\n";
		}
	}
	if (checkManager(*this) == 0) {
		system("cls");
		cout << "Manager already Exists\nTry Again\n";
		registeration(1);
	}
	else {
		insertManager(*this);
		manager m;
		m.managerMenu();
	}
}
void user::registeration(int b, int a) {
	cout << "Customer Registeration called\n";
	cout << "Enter Name: ";
	cin >> name;
	cout << "Enter password: ";
	cin >> password;
	cout << "Enter Address: ";
	cin >> address;
	cout << "Enter Gender: ";
	cin >> gender;
	cout << "Enter Phone Number: ";
	cin >> phone;
	cout << "Enter CNIC: ";;
	cin >> CNIC;
	if (strlen(CNIC) != 13) {
		system("cls");
		cout << "Invalid Numbers\n";
		registeration(1, 1);
	}
	else if(checkCustomer(*this)==0) {
		system("cls");
		cout << "Customer Already Exists\n";
		registeration(1, 1);
	}
	else {
		insertCustomer(*this);
		customer c;
		c.showShop();
	}

}