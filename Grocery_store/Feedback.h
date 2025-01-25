#pragma once
#include <iostream>

using namespace std;

class feedback {
	int ratings;
	char feed[100];
	char option;
	int num=0;
public:
	void feedbackmenu();
	void showFeedBack();
	void deleteFeedBack();
	void giveFeedBack();

	void insertFeedback(feedback);
	bool delfeed(int);
};

void feedback::feedbackmenu() {
	system("cls");
	system("color de");
	cout << "Do you want to give feedback ?\nPress 1 for yes and 2 for No: ";
	cin >> option;
	switch (option) {
	case '1':
		giveFeedBack();
		break;
	case '2':
		cout << "JAZAKALLAH for shooping with us\Do come again\n";
		break;
	default:
		cout << "Invalid input\n ";

	}
}

void feedback::showFeedBack() {
	system("cls");
	system("color de");
	cout << "Showing Feedback\n";
	feedback f;
	ifstream myFile("FeedBack.bin", ios::binary);
	while (myFile.read((char*)&f, sizeof(f))) {
		cout << "No. " << f.num << "\t" << "Ratings:  " << f.ratings << "\t" << "Comments: " << f.feed << endl;
	}
	myFile.close();

}

void feedback::deleteFeedBack(){
	system("cls");
	cout << "Deleting Feedback\n";
	cout << "Enter Feedback Number you want to delete: ";
	cin >> num;
	if (delfeed(num) == 1) {
		return;
	}
	else {
		cout << "This Feedback Number does not exist\n";
	}
}
void feedback::giveFeedBack() {
	cout << "Customer FeedBack Called\n";
	cout << "Rate us out of 5: ";
	cin >> ratings;
	cin.ignore();
	cout << "Add some comments: ";
	cin.getline(feed,100);
	cin.ignore();
	cout << "Enter feedback number: ";
	cin >> num;
	insertFeedback(*this);

}

void feedback::insertFeedback(feedback f) {
	ofstream myFile("FeedBack.bin", ios::binary | ios::app);
	if (myFile.write((char*)&f, sizeof(f)))
		cout << "Your Feedback has been saved" << endl;
	
	myFile.close();
}

bool feedback::delfeed(int n) {
	int t=0;
	feedback temp;
	fstream myFile("FeedBack.bin", ios::in | ios::out | ios::binary);
	ofstream myFile_temp("temp.bin", ios::app | ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp))) {
		if (temp.num!=n) {
			myFile_temp.write((char*)&temp, sizeof(temp));
		}
		else {
			t = 1;
		}
	}
	myFile.close();
	myFile_temp.close();
	remove("FeedBack.bin");
	rename("temp.bin", "FeedBack.bin");
	cout << "\n\FeedBack Removed\n\n";
	return t;
}