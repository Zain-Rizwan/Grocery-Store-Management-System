#pragma once
#include "../i21-2500_Project/User.h"
#include <chrono>


using namespace std;

class Grocery_Store {
	user u;
	char option1;
	char option2;

public:
	void menu() {
		auto starter = chrono::steady_clock::now();
		system("cls");
		system("color 8e");
		cout << "Choose One Of the Following Options:\n";
		cout << "1. Admin\n";
		cout << "2. Manager\n";
		cout << "3. Customer\n";
		cout << "4. Exit\n";
		cout << "Enter Option: ";
		cin >> option1;
		switch (option1) {
		case '1':
			/*system("cls");
			cout << "What do you want to do:\n1. Register\n2. Login\nEnter: ";
			cin >> option2;
			if (option2 == 2) {*/
				system("cls");
				u.login();
		/*	}
			else if (option2 == 1) {
				system("cls");
				u.registeration();
			}
			else {
				system("cls");
				Grocery_Store g;
				cout << "Invalid Input\n";
				g.menu();

			}*/
			break;

		case '2':
				system("cls");
				u.login(1);
			
			break;
		case '3':
			system("cls");
			cout << "What do you want to do:\n1. Register\n2. Login\nEnter: ";
			cin >> option2;
			if (option2 == '2') {
				system("cls");
				u.login(1, 1);
			}
			else if (option2 == '1') {
				system("cls");
				u.registeration(1,1);
			}
			else {
				system("cls");
				Grocery_Store g;
				cout << "Invalid Input\n";
				g.menu();
				
			}
			break;
		case'4':
			return;
			//exit(0);
			break;
		default:
			system("cls");
			cout << "Invalid Option Choosed\nTry Again:";
			Grocery_Store g;
			cout << "Invalid Input\n";
			g.menu();

		}
	}




};

