#pragma once

#include <iostream>
#include <fstream>

using namespace std;


class payment {
	char option;

public:
	void paymentMenu();
	virtual void paymoney();

};

class COD :public payment {

public:
	void paymoney() {
		cout << "Your payment has been made in Cash on delivery\n";
	}
};


class card :public payment {

public:
	void paymoney() {
		cout << "Your payment has been made by your Credit Card\n";
	}
};

class easypaisa :public payment {

public:
	void paymoney() {
		cout << "Your payment has been made by Easy Paisa\n";
	}
};

class jazz :public payment {

public:
	void paymoney() {
		cout << "Your payment has been made by Jazz Cash\n";
	}
};

void payment::paymentMenu() {
	system("cls");
	system("color ae");
	feedback f;
	payment * z = new jazz;
	payment * y = new easypaisa;
	payment * x = new card;
	payment* p=new COD;
	payment * a = new COD;
	cout << "Select Payment Method:-\n ";
	cout << "1. COD (Cash on Delivery)\n";
	cout << "2. Payment through Card\n";
	cout << "3. Easy Paisa\n";
	cout << "4. JazzCash\n";
	cout << "5. Exit\n";
	cout << "Choose option: ";
	cin >> option;
	switch (option) {
	case '1':
		p->paymoney();
		f.feedbackmenu();
		break;
	case '2':
		x->paymoney();
		f.feedbackmenu();
		break;
	case '3':
		y->paymoney();
		f.feedbackmenu();
		break;
	case '4':
		z->paymoney();
		f.feedbackmenu();
		break;
	case '5':
		exit(0);
		break;
	}


}
void payment::paymoney() {
	cout << "Payment\n";
}
