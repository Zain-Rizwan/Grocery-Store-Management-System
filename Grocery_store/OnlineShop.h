#pragma once
#include <iostream>
#include <fstream>

#include "../i21-2500_Project/User.h"
#include "Customer.h"
#include "Payment.h"

using namespace std;

class Online_Shop {
	char op,ap;
	bool oop = true;
	int TotalAmount=0;
	char product[10];
	bool z=true;
	int no;
	payment p;
public:
	void showShop();
	void showCatalog();

	bool checkproduct(char*);
	bool checkamount(char *,int);
	void addtocart(char*, int);
	void removequantity(char*, int);
};

void Online_Shop::showShop() {
	system("cls");
	system("color Ce");
	cout << "1. Show Catalog\n";
	cout << "2. Add to Cart\n";
	cout << "3. Show Cart\n";
	cout << "4. CheckOut\n";
	cout << "5. Go to Customer Menu\n";

	while (oop) {
		cout << "Choose: ";
		cin >> op;
		switch (op) {
		case '1':
			cout << "Showing catalog\n";
			showCatalog();
			//oop = false;
			break;
		case '2':
			char choice;
			while (z) {
				cout << "\nEnter name of product: ";
				cin >> product;
				if (checkproduct(product) == 1) {
					cout << "How many " << product << " do you want to Buy: ";
					cin >> no;
					if (checkamount(product, no) == 1) {
						addtocart(product, no);
						inventory i;
						i.AddCart(product, no);
						cout << "\nProduct bought\n";
					}
					else {
						cout << "\nThis amount of " << product << " is not Available in store\n";
					}
				}
				else {
					cout << "\nProduct does not exist\n";
				}
				cout << "\nPress 1 to go back to menu Or press any other key to keep shopping: ";
				cin >> choice;
				if (choice == '1') {
					break;
				}
			}
			//oop = false;
		case '3':
			inventory x;
			cout << "Showing to cart\n";
			x.ShowCart();
			//oop = false;

			break;
		case '4':
			cout<<"Checkking out\n";
			cout << TotalAmount << endl;
			inventory y;
			y.RemoveCart();
			p.paymentMenu();
			//oop = false;
			break;
		case '5':
			//oop = false;
			return;
			break;
		default:
			cout << "\n\nInvalid Input\n Try agin\n\n";
		}

		cout << "\nPress any Key to go back to Catalog Menu!\n\n ";
		cin >> ap;
		showShop();

	}

}

void Online_Shop::showCatalog() {
	inventory z;
	ifstream myFile("Inventory.bin", ios::binary);
	while (myFile.read((char*)&z, sizeof(z))) {
		cout << "Name: " << z.n << "\t" << "Price: " <<z. price << "\t" << "Quantity: " << z.quantity << endl;
	}
	myFile.close();
}

bool Online_Shop::checkproduct(char* p) {
	inventory temp;
	ifstream myFile("Inventory.bin", ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (strcmp(temp.n, p) == 0) {
			myFile.close();
			return 1;
		}
	}
	myFile.close();
	return 0;
}

bool Online_Shop::checkamount(char* p,int n) {
	inventory temp;
	ifstream myFile("Inventory.bin", ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (strcmp(temp.n, p) == 0) {
			if (temp.quantity >= n) {
				myFile.close();
				return 1;
			}
			//cout << "Name: " << temp.n << "\t" << "Price: " << temp.price << "\t" << "Quantity: " << temp.quantity << endl << endl;
		}
	}
				myFile.close();
	return 0;
}

void Online_Shop::addtocart(char* p, int n) {
	int tempAmount = 0;
	inventory temp;
	ifstream myFile("Inventory.bin", ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (strcmp(temp.n, p) == 0) {
			if (temp.quantity >= n) {
				tempAmount = n * temp.price;
				TotalAmount += tempAmount;
				myFile.close();
				removequantity(p,n);
				return;
			}
			//cout << "Name: " << temp.n << "\t" << "Price: " << temp.price << "\t" << "Quantity: " << temp.quantity << endl << endl;
		}
	}
	myFile.close();
	return ;
}

void Online_Shop::removequantity(char* p, int n) {
	inventory temp;
	fstream myFile("Inventory.bin", ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (strcmp(temp.n, p) != 0) {
			myFile_temp.write((char*)&temp, sizeof(temp));
		}
		else {
			temp.quantity -= n;
			myFile_temp.write((char*)&temp, sizeof(temp));
		}

	}
	myFile.close();
	myFile_temp.close();
	remove("Inventory.bin");
	rename("temp.bin", "Inventory.bin");
	cout << "\n\nQuantity updated\n\n";
}