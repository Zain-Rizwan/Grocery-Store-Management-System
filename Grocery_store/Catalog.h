#pragma once
#include <iostream>

using namespace std;

class catalog {
	char cname[10];
	int quantity;
	int price;
	

public:
	void catalogMenu();
	void showCatalog();
	void addCatalog();
	void removeCatalog();
	void updateCatalog();
	bool insertCatalog(catalog);

};
bool catalog::insertCatalog(catalog c) {
	ofstream myFile("catalog.bin", ios::binary | ios::app);
	if (myFile.write((char*)&c, sizeof(c))) {
		cout << "Object Successfully Inserted!" << endl;
		myFile.close();
		return 1;
	}
	else {
		cout << "Object Insertion Failed" << endl;
		myFile.close();
		return 0;
	}
}

void catalog::showCatalog() {
	system("cls");
	cout << "Showing All cATalog\n";
	cout << "\n\n\nCatalog:\n\n";
	catalog c;
	ifstream myFile("catalog.bin", ios::binary);
	while (myFile.read((char*)&c, sizeof(c))) {
		cout << "Name: " << c.cname << "\t" << "Price: " << c.price << "\t" << "Quantity: " <<c.quantity << endl;
	}
	myFile.close();
	cout << "\n\n\n";
}

void catalog::addCatalog() {
	system("cls");
	cout << "Adding Catalog\n\n";
	cout << "Enter item name: ";
	cin >> cname;
	cout << "Enter price: ";
	cin >> price;
	cout << "Enter Quantity: ";
	cin >> quantity;
	insertCatalog(*this);
}
void catalog::removeCatalog() {
	system("cls");
	cout << "Removing Catalog\n";
	cout << "Enter product you want to remove: ";
	cin >> cname;
	catalog temp;
	fstream myFile("catalog.bin", ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (strcmp(temp.cname, cname) != 0) {
			myFile_temp.write((char*)&temp, sizeof(temp));
		}
	}
	myFile.close();
	myFile_temp.close();
	remove("catalog.bin");
	rename("temp.bin", "catalog.bin");
	cout << "\n\nProduct Removed\n\n";

}
void catalog::updateCatalog() {
	system("cls");
	cout << "Updating Catalog\n";
}

void catalog::catalogMenu() {

}