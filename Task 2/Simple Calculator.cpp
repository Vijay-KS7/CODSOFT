#include <iostream>
#include<windows.h>
#include<cstdlib>
#include<thread>
#include<chrono>
using namespace std;

HANDLE lethandle = GetStdHandle(STD_OUTPUT_HANDLE);

void txtcolor(string color){
	
	if(color == "blue"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_BLUE);
	}
	else if(color == "green"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_GREEN);
	}
	else if(color == "red"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_RED);
	}
	else if(color == "bright"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_INTENSITY);
	}
	else if(color == "cyan"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_BLUE | FOREGROUND_GREEN);
	}
	else if(color == "magenta"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_BLUE | FOREGROUND_RED);
	}
	else if(color == "yellow"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_GREEN | FOREGROUND_RED);
	}
	else if(color == "white"){
		SetConsoleTextAttribute(lethandle,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	}
	
}

void calc_banner() {

	cout << endl;
	txtcolor("green");

	cout << "\t\t\t=========================================================================" << endl;
	cout << "\t\t\t|                       Simple Calculator Program                       |" << endl;
	cout << "\t\t\t=========================================================================" << endl;

	cout << endl;
	txtcolor("cyan");
}

void Welcmsg() {

	cout << "\t\t\t\t\t\t  😎 *--WELCOME--* 😎" << endl << endl;

}

void clearScreen() {
	system("cls");
}

void endmsg(){
	
	clearScreen();
	
	txtcolor("green");
	
	cout << endl;
	cout<<"\t\t\t\t*************************************************************"
	    <<endl<<endl;
	cout<<"\t\t\t\t  * * * * * * * * *   Thanks For Coming   * * * * * * * * * "<<endl<<endl;
	cout<<"\t\t\t\t*************************************************************"
	    <<endl;
	    
	txtcolor("white");
	
}

int calculator(double num1, double num2) {

	int choice;

	while (true) {

		cout << endl;
		txtcolor("yellow");
		cout << "\t\t\t\t\t Select an operation:\n" << endl;
		txtcolor("magenta");
		cout << "\t\t\t\t\t   0 --> Addition\n"
		     << "\t\t\t\t\t   1 --> Subtraction\n"
		     << "\t\t\t\t\t   2 --> Multiplication\n"
		     << "\t\t\t\t\t   3 --> Division\n"
		     << "\t\t\t\t\t   4 --> Remainder\n"
		     << "\t\t\t\t\t   5 --> Average\n"
		     << endl;
		txtcolor("cyan");
		cout << "\t\t\t\t\t Enter:";
		txtcolor("white");
		cin >> choice;
		cout << endl;
		txtcolor("yellow");
		cout << "\t\t\t\t\t Result ";

		switch (choice) {

			case 0:
				cout << num1 << " + " << num2 << " = " << num1 + num2 << endl
				     << endl;
				break;
			case 1:
				cout << num1 << " - " << num2 << " = " << num1 - num2 << endl
				     << endl;
				break;
			case 2:
				cout << num1 << " * " << num2 << " = " << num1 * num2 << endl
				     << endl;
				break;
			case 3:
				cout << num1 << " / " << num2 << " = " << num1 / num2 << endl
				     << endl;
				break;
			case 4:
				cout << num1 << " % " << num2 << " = " << (int)num1 % (int)num2
				     << endl
				     << endl;
				break;
			case 5:
				cout << "(" << num1 << " + " << num2 << ")/2 = " << (num1 + num2) / 2 << endl
				     << endl;
				break;
			default:
				continue;
		}
		txtcolor("magenta");
		cout << "\t\t\t\t\t   1 --> Any other operation\n"
		     << "\t\t\t\t\t   2 --> Enter new numbers\n"
		     << "\t\t\t\t\t   3 --> Exit\n"
		     << endl;
		txtcolor("cyan");
		cout << "\t\t\t\t\t Enter:";
		txtcolor("white");
		cin >> choice;
		cout << endl;

		if(choice == 1) {
			continue;

		} else if(choice == 2) {
			break;

		} else if(choice == 3) {
			return 1;
		}
	}
	clearScreen();
	calc_banner();
	Welcmsg();
	return 0;
}

int main() {

	SetConsoleOutputCP(CP_UTF8);
	calc_banner();
	Welcmsg();

	while (true) {

		double num1;
		double num2;

		txtcolor("cyan");
		cout << "\t\t\t\t\t Enter the value of first number:" << endl;
		cout << "\t\t\t\t\t ";
		txtcolor("white");
		cin >> num1;
		cout << endl;

		txtcolor("cyan");
		cout << "\t\t\t\t\t Enter the value of second number:" << endl;
		cout << "\t\t\t\t\t ";
		txtcolor("white");
		cin >> num2;

		int exit = calculator(num1,num2);

		if(exit == 1) {
			clearScreen();
			calc_banner();
			Welcmsg();

			cout << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t\t       Exiting.";
			this_thread::sleep_for(chrono::seconds(1));
			cout << ".";
			this_thread::sleep_for(chrono::seconds(1));
			cout << ".";
			this_thread::sleep_for(chrono::seconds(1));
			cout << ".";
			break;
		}

		cout << endl;
	}

	endmsg();

	return 0;
}