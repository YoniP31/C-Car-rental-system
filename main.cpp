#include <iostream>
#include <string>
#include "user.h"
using namespace std;

char Menu();
int Fare(int hour);

int main() {
	//Main Menu
	char s = Menu();
	string name, phone, IC;
	Customer user1("Yoni", "11111111", "12345");
	if (s == 'A') {
		cout << "nothing yet\n";
	}
	else if (s == 'C') {
		//Register/Login Menu
		int choise;
		string c = "yes";
		cout << "For registration enter: 1" << endl;
		cout << "For login enter: 2" << endl;
		cin >> choise;
		if (choise == 1) {
			user1.Register();
		}
		else if(choise == 2) {
			while (user1.LoggIn() == 0) {
				cout << "user does not exist" << endl;
			}	
		}
		while (c == "yes") {
			user1.Show_Cars();
			user1.Order_Car(user1);
			cout << "if you want to order another car enter: yes" << endl;
			cout << "if you want to log out enter: logout" << endl;
			cin >> c;
		}
		main();
	}
	string c;
	cout << "enter any key to exit" << endl;
	cin >> c;
	return 0;
}

char Menu() {
	char s;
	cout << "For Administrator enter: A\n" << "For Customer enter : C" << endl;
	cin >> s;
	return s;
}

int Fare(int hour) {
	int fare = (rand() % 5 + 5) * hour;
	return fare;
}
