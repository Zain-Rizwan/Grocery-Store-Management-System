#pragma once
#include <iostream>
#include <fstream>
#include "../i21-2500_Project/User.h"
#include "Grocery_Store.h"
#include "Catalog.h"
#include "Feedback.h"
#include "Manager.h"
#include "Checkout_Simulation.h"
#include "Customer.h"

using namespace std;

class admin : public user {
	char location[20];
	int aop;
	char x;
	catalog c;
	feedback f;
	simulation zain;
public:
	void AdminMenu();
	void createManager();//	1
	void removeManager();// 2
	void showManagers();//	3
	void showCatalog();//	4
	void AddCatalog();//	5
	void RemoveCatalog();//	6
	void UpdateCatalog();//	7
	void CheckOut();	//	8
	void ShowFeedback();//	9
	void DeleteFeedback();//10
	void showRevenue();
};

void admin::AdminMenu() {
	
	system("cls");
	system("color 5e");
	bool z=false;
	//do {
		cout << "AdminMenu Called\n";
		cout << "Select One of the Following Options:-\n";
		cout << " 1. Create Manager\n ";
		cout << "2. Remove Manager\n ";
		cout << "3. Show Managers\n ";
		cout << "4. Show Catalog\n ";
		cout << "5. Add Catalog\n ";
		cout << "6. Remove Catalog\n ";
		cout << "7. Update Catalog\n ";
		cout << "8. Checkout\n ";
		cout << "9. Show FeedBack\n ";
		cout << "10.Delete Feedback\n ";
		cout << "11.Show store Revenue\n";
		cout << "12.Go Back to Main Menu\n ";
		cout << "13.Show All CheckOut Simulation\n ";
		cout << "Choose: ";
		cin >> aop;
		switch (aop) {
		case 1:
			z = 1;
			user u;
			u.registeration(1);
			cout << "Press any key to go back to Admin Menu!";
			cin >> x;
			AdminMenu();
			break;
		case 2:
			z = 1;
			removeManager();
			cout << "Press any key to go back to Admin Menu!";
			cin >> x;
			AdminMenu();
			break;
		case 3:
			z = 1;
			showManagers();
			cout << "Press any key to go back to Admin Menu!";
			cin >> x;
			AdminMenu();
			break;
		case 4:
			z = 1;
			c.showCatalog();
			cout << "Press any key to go back to Admin Menu!";
			cin >> x;
			AdminMenu();
			break;
		case 5:
			z = 1;
			c.addCatalog();
			cout << "Press any key to go back to Admin Menu!";
			cin >> x;
			AdminMenu();
			break;
		case 6:
			z = 1;
			c.removeCatalog();
			cout << "Press any key to go back to Admin Menu!";
			cin >> x;
			AdminMenu();
			break;
		case 7:
			z = 1;
			c.updateCatalog();
			cout << "Press any key to go back to Admin Menu!";
			cin >> x;
			AdminMenu();
			break;
		case 8:
			z = 1;
			cout << "Press any key to go back to Admin Menu!";
			cin >> x;
			AdminMenu();
			break;
		case 9:
			z = 1;
			f.showFeedBack();
			cout << "Press any key to go back to Admin Menu!";
			cin >> x;
			AdminMenu();
			break;
		case 10:
			z = 1;
			f.deleteFeedBack();
			cout << "Press any key to go back to Admin Menu!";
			cin >> x;
			AdminMenu();
			break;
		case 11:
			showRevenue();
			cout << "Press any key to go back to Admin Menu!";
			cin >> x;
			break;
		case 12:
			z = 1;
			Grocery_Store g;
			g.menu();
			break;
		case 13:
			zain.showTime();
			cout << "Press any key to go back to Admin Menu!";
			cin >> x;
			break;
		default:
			cout << "\nInvalid Option Choosed !!!\n\n";

		}
	//} while (!z);

}

void admin::createManager() {
	cout << "Creating Mangaer\n";

}

void admin::removeManager(){
	cout << "Removing Mangaer\n";
	bool z = 1;
	while (z) {
		cout << "Enter Name of the Manager: ";
		cin >> name;
		manager temp;
		fstream myFile("Manager.bin", ios::in | ios::out | ios::binary);
		ofstream myFile_temp("temp.bin", ios::app | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {

			if (strcmp(temp.name, name) != 0) {
				myFile_temp.write((char*)&temp, sizeof(temp));
			}
			else {
				z = false;
			}

		}
		myFile.close();
		myFile_temp.close();
		remove("Manager.bin");
		rename("temp.bin", "Manager.bin");
		if (z = false) {
			system("cls");
			cout << "This NAME of Manager Does not exist\nTry Again\n";
		}
		cout << "Manager Removed!\n";
	}
}
void admin::showManagers() {
	manager temp;
	ifstream myFile("Manager.bin", ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		cout << temp.name << "\t" << temp.password << "\t" << temp.location;
		cout<< endl << endl;
	}
	myFile.close();
}

void admin::showCatalog() {
	cout << "Showing Catalog\n";
	catalog c;
	c.showCatalog();
}

void admin::AddCatalog() {
	catalog s;
	s.addCatalog();
}
void admin::RemoveCatalog() {
	catalog t;
	t.removeCatalog();
}
void admin::UpdateCatalog() {
	cout << "Updating Catalog\n";
}

void admin::CheckOut() {
	cout << "Checkout Simulator Called\n";
}
void admin::ShowFeedback() {
	feedback f;
	f.showFeedBack();
}
void admin::DeleteFeedback() {
	feedback f;
	f.deleteFeedBack();
}

void admin::showRevenue() {
	customer temp;
	int z = 0;
	ifstream myFile("Store_Revenue.bin", ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		z += temp.TotalAmount;
	}
	cout << "\nTotal Revenue of Store is: " << z << "Rs" << endl;;
	myFile.close();
}