// mRodriguezWeatherStation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include "val.h"
#include "Weather_Measurement.h"
using namespace std;
//#define arraySize 4

string stationName = "", windDirection = "";
int currentTemp, windSpeed, numElements;
int *tempArray;
int *speedArray;
string *directionArray;
int index = 0, maxArray = 0;
weatherMeasurement_t *report;

int enterSizeOfArray() {
	int result;
	string userInput;
	string validInput = "[0-9]+";
	do {
		cout << "Enter amount of weather reports you'd like to save: " << endl;
		getline(cin, userInput);
	} while (!valid_input(userInput, validInput) || userInput == "0");

	stringstream(userInput) >> result;
	return result;
}

void setArrays(int size) {
	tempArray = new int[size];
	speedArray = new int[size];
	directionArray = new string[size];
	maxArray = size - 1;
}

int enterMenu() {
	int result;
	string userInput;
	string validInput = "[1-5]";
	do {
		cout << "\nType 1 to enter in weather reading" << endl;
		cout << "Type 2 to print weather reading" << endl;
		cout << "Type 3 to print weather history" << endl;
		cout << "Type 4 to quit" << endl;
		getline(cin, userInput);
	} while (!valid_input(userInput, validInput));

	stringstream(userInput) >> result;
	return result;
}

int main()
{
	int i = 0;
	char input[20];
	int sval = 0;
	string myString;

	cout << "Enter weather station name: " << endl;
	getline(cin, myString);
	stringstream(myString) >> stationName;

	int sizeOfArray = enterSizeOfArray();
	//setArrays(sizeOfArray);
	report = new weatherMeasurement_t[sizeOfArray];

	do {
		sval = enterMenu();
		cin.clear();

		switch (sval) {
		case 1:
			i = sizeOfArray-1;

				do {
					report[i] = report[i - 1];
					i--;
				} while (i > 0);
				report[0] = enterWeather();

			if (numElements != sizeOfArray) numElements++;
			break;
		case 2:
			if (numElements > 0) printWeather(report[0]);
			else	cout << "no elements entered" << endl;
			break;
		case 3:
			for (int i = 0; i < numElements; i++) {
				cout << "\n";  printWeather(report[i]);
			}
				break;
		case 4:
			exit(0);
			break;
			}

		} while (true);

		return 0;

}