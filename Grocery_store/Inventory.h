#pragma once
#include <iostream>
#include <fstream>
#include "../i21-2500_Project/User.h"

using namespace std;

class inventory {
public:
	char n[10];
	int price;
	int quantity;
	char op;
	void insertInventory(inventory);
	void removeProduct(char*);
	void updateProduct();
	void search();
	void show();

	bool checkProdect(char*);
	void updatePrice(char* ,int);
	void updateQuantity(char* ,int);
	void AddCart(char*, int);
	void RemoveCart();
	void ShowCart();
};

void inventory::search() {
	cout << "Enter Name of Product you want to Search: ";
	cin >> n;
	inventory temp;
	ifstream myFile("Inventory.bin", ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (strcmp(temp.n, n) == 0) {
			cout << "\nProduct Found\n";
			cout << "Name: " << temp.n << "\t" << "Price: " << temp.price << "\t" << "Quantity: " << temp.quantity << endl<<endl;
			myFile.close();
			return;
		}
	}
	cout << "\n\nProduct not Found !!!\n";
}

void inventory::insertInventory(inventory z) {
	ofstream myFile("Inventory.bin", ios::binary | ios::app);
	if (myFile.write((char*)&z, sizeof(z)))
		cout << "Object Successfully Inserted!" << endl;
	else
		cout << "Object Insertion Failed" << endl;
	myFile.close();
}

void inventory::removeProduct(char* z) {
	inventory temp;
	fstream myFile("Inventory.bin", ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);
	int i = 1;
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (strcmp(temp.n, z) != 0) {
			myFile_temp.write((char*)&temp, sizeof(temp));
		}
	}
	myFile.close();
	myFile_temp.close();
	remove("Inventory.bin");
	rename("temp.bin", "Inventory.bin");
	cout << "\n\nProduct Removed\n\n";
}

void inventory::updateProduct() {
	cout << "Enter Name of the product: ";
	cin >> n;
	if (checkProdect(n) == 0) {
		cout << "\nProduct does not exist\n\n";
		updateProduct();
	}
	else {
		cout << "\nProduct Found\n";
		cout << "What do you want to update:\n1. Price\n2. Quantity\nChoose: ";
		cin >> op;
		if (op == '1') {
			cout << "Enter new price of the product: ";
			cin >> price;
			updatePrice(n,price);
		}
		else if (op == '2') {
			cout << "Enter new Quantity of the product: ";
			cin >> quantity;
			updateQuantity(n, quantity);
		}
	}
}

void inventory::updatePrice(char * z,int p) {
	inventory temp;
	fstream myFile("Inventory.bin", ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (strcmp(temp.n, z) != 0) {
			myFile_temp.write((char*)&temp, sizeof(temp));
		}
		else {
			temp.price = p;
			myFile_temp.write((char*)&temp, sizeof(temp));
		}

	}
	myFile.close();
	myFile_temp.close();
	remove("Inventory.bin");
	rename("temp.bin", "Inventory.bin");
	cout << "\n\nPrice updated\n\n";
}

void inventory::updateQuantity(char * z,int q) {
	inventory temp;
	fstream myFile("Inventory.bin", ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (strcmp(temp.n, z) != 0) {
			myFile_temp.write((char*)&temp, sizeof(temp));
		}
		else {
			temp.quantity = q;
			myFile_temp.write((char*)&temp, sizeof(temp));
		}

	}
	myFile.close();
	myFile_temp.close();
	remove("Inventory.bin");
	rename("temp.bin", "Inventory.bin");
	cout << "\n\nQuantity updated\n\n";
}

bool inventory::checkProdect(char* z) {
	inventory temp;
	ifstream myFile("Inventory.bin", ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (strcmp(temp.n, z) == 0) {
			myFile.close();
			return 1;
		}
	}
			myFile.close();
			return 0;
}

void inventory::show() {
	cout << "\n\n\nInventory:\n\n";
	ifstream myFile("Inventory.bin", ios::binary);
	while (myFile.read((char*)&*this, sizeof(*this))) {
		cout << "Name: "<<n << "\t" << "Price: " << price << "\t" << "Quantity: " << quantity << endl;
	}
	myFile.close();
	cout << "\n\n\n";
}

void inventory::AddCart(char* p, int no) {
	inventory z;
	strcpy_s(z.n, p);
	z.quantity = no;
	ofstream myFile("Cart.bin", ios::binary | ios::app);
	if (myFile.write((char*)&z, sizeof(z)))
		cout << "Cart Added!" << endl;
	else
		cout << "Not Added to cart\n" << endl;
	myFile.close();
}

void inventory::RemoveCart() {
	remove("Cart.bin");
}

void inventory::ShowCart() {
	inventory z;
	ifstream myFile("Cart.bin", ios::binary);
	while (myFile.read((char*)&z, sizeof(z))) {
		cout << "Name: " << z.n << "\t" << "Quantity: " << z.quantity << endl;
	}
	myFile.close();
}