#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class simulation {
	double timeTaken;
public:
	simulation() {
		timeTaken = 0;
	}
	simulation(double s) {
		timeTaken = s;
	}
	void saveTime() {
		ofstream myFile("Checkout_Simulator.bin", ios::binary | ios::app);
		if (myFile.write((char*)&*this, sizeof(*this)))
			cout << "\nTime saved of Customer" << endl;
		myFile.close();
	}
	void showTime() {
		cout << "Showing All Customer Time:\n\n";
		simulation s;
		int i = 1;
		ifstream myFile("Checkout_Simulator.bin", ios::binary);
		while (myFile.read((char*)&s, sizeof(s))) {
			cout << "Time Taken by "<<i<<" Customer: " << s.timeTaken<<" Seconds" << endl;
			++i;
		}
		myFile.close();
	}
};