#pragma once
#include <iostream>

#include "User.h"
#include "Inventory.h"

using namespace std;

class manager :public user {
	int aop;
	char x;
public:
	void managerMenu();
	void showInventory();
	void AddInventory();
	void removeInventory();
	void updateInventory();
	void searchInventory();

};
void manager::managerMenu() {
	system("cls");
	system("color 4e");
	cout << "Select any Option:\n";
	cout << "1. Show Inventory\n";
	cout << "2. Add Item in Inventory\n";
	cout << "3. Remove Item in Inventory\n";
	cout << "4. Update Item in Inventory\n";
	cout << "5. Search Item Inventory\n";
	cout << "6. Go Back To Main Menu\n";
	cout << "Choose: ";
	cin >> aop;
	switch (aop) {
	case 1:
		showInventory();
		break;
	case 2:
		AddInventory();
		break;
	case 3:
		removeInventory();
		break;
	case 4:
		updateInventory();
		break;
	case 5:
		searchInventory();
		break;
	case 6:
		Grocery_Store g;
		g.menu();
		break;
	default: {
		managerMenu();
		cout << "\nInvalid Option Choosed !!!\n\n";
	}

	}

}

void manager::showInventory() {
	inventory i;
	i.show();
	cout << "Press any key to go back to Menu: ";
	cin >> x;
	managerMenu();
}
void manager::AddInventory() {
	inventory i;
	cout << "Enter Name of Product: ";
	cin >> i.n;
	cout << "Enter its Price: ";
	cin >> i.price;
	i.quantity = 100;
	if (i.checkProdect(i.n) == 0) {
		i.insertInventory(i);
	}
	else {
		cout << "\nItem already exists\n\n";
	}
	cout << "Press any key to go back to Menu: ";
	cin >> x;
	managerMenu();
}
void manager::removeInventory() {
	inventory i;
	cout << "Enter Name of product you want to remove: ";
	cin >> i.n;
	i.removeProduct(i.n);

	cout << "Press any key to go back to Menu: ";
	cin >> x;
	managerMenu();
}
void manager::updateInventory() {
	inventory i;
	i.updateProduct();
	cout << "Press any key to go back to Menu: ";
	cin >> x;
	managerMenu();
}
void manager::searchInventory() {
	inventory i;
	i.search();

	cout << "Press any key to go back to Menu: ";
	cin >> x;
	managerMenu();
}