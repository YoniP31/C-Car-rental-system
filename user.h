#pragma once

#include <fstream>
#include <string>
using namespace std;

class Customer {
protected:
	string username, password, name, phone, IC;
public:
	Customer(string name, string phone, string IC);
	int Register();
	int LoggIn();
	void Show_Cars();
	void Order_Car(Customer& user);
	void Log_File(Customer& user, string car_details, string car, string brand, string model, int hour, int fare);
};
