#include <iostream>
#include <string>
#include <fstream>
#include "user.h"
using namespace std;

int Fare(int hour);

Customer::Customer(string name, string phone, string IC)
	: name(move(name)), phone(move(phone)), IC(move(IC)){

}

int Customer::Register() {
	cout << "Enter username: "; cin >> username;
	cout << "Enter password: "; cin >> password;

	//check if user already exists
	string item;
	ifstream ifFile("Customer.txt");
	while (ifFile >> item) {
		if (item == username) {
			ifFile >> item;
			if (item == password) {
				cout << "User already exists" << endl;
				ifFile.close();
				return 0;
			}
		}
	}
	ifFile.close();
	ofstream File("Customer.txt", ios::app); {
		File << username << " " << password << endl;
		File.close();
	}
	cout << "User Registered" << endl;
	return 1;
}

int Customer::LoggIn() {
	cout << "Enter username: "; cin >> username;
	cout << "Enter password: "; cin >> password;

	//check if user exists
	string item;
	ifstream ifFile("Customer.txt");
	while (ifFile >> item) {
		if (item == username) {
			ifFile >> item;
			if (item == password) {
				cout << "Hello " << name << endl;
				ifFile.close();
				return 1;
			}
		}
	}
	ifFile.close();
	return 0;
}

void Customer::Show_Cars() {
	string line;
	cout << "Here are the available cars: " << endl;
	ifstream openFile("Available Cars.txt");
	while (getline(openFile, line)) {
		cout << line << endl;
	}
	openFile.close();
}

void Customer::Order_Car(Customer& user) {
	int carnum, hour, fare;
	string car_details;
	cout << "Choose a car by entering the car number: ";
	cin >> carnum;
	ifstream openFile("Available Cars.txt");
	for (int i = 0; i < carnum - 1; i++) {
		getline(openFile, car_details);
	}
	cout << "How many hours? ";
	cin >> hour;
	fare = Fare(hour);
	cout << "The fare will be: " << fare << "$" << endl;
	string num, car, brand, model;
	openFile >> num >> car >> brand >> model;
	openFile.close();
	Log_File(user, car_details, car, brand, model, hour, fare);
}

void Customer::Log_File(Customer& user, string car_details, string car, string brand, string model,int hour, int fare) {
	ofstream writeFile("Logs.txt", ios::app);
	writeFile << "Name: " << user.name << endl;
	writeFile << "Phone: " << user.phone << endl;
	writeFile << "IC: " << user.IC << endl;
	writeFile << "Car: " << car << endl;
	writeFile << "Brand: " << brand << endl;
	writeFile << "Model: " << model << endl;
	writeFile << "Hour: " << hour << endl;
	writeFile << "Fare: " << fare << "$" << endl;
	writeFile << "--------------------------" << endl;
}