#include<iostream>
#include "temp_conv.h"

using namespace std;

#define USE_HEADER1 1            // Ex 2 , 3
#define DEBUG 1

#ifdef USE_HEADER1

#if USE_HEADER1 == 1
 #include "header1.h"
#else
 #include "header2.h"

#endif

#endif

#ifdef DEBUG


void debug_message() {
	cout << "\n [DEBUG] : PROCESS ENDED" << endl;
}

#endif

void op_sy_message() {                   //Ex 4
#ifdef _WIN32
	cout << "Hello, Windows!" << endl;
#elif __linux__
	cout << "Hello, Linux!" << endl;
#endif
}

int main() {                                 // Ex 1
	double celsius_temp, fahrenheit_temp;

	f();
	
	cout << endl << endl;
	op_sy_message();
	cout << endl << endl;

	cout << "Enter temperature in Celsius :";
	cin >> celsius_temp;
	double converted_to_fahrenheit = celsius_to_fahrenheit(celsius_temp);
	cout << "The temperature in Fahrenheit is " << converted_to_fahrenheit << endl;

	cout << "Enter temperature in Fahrenheit :";
	cin >> fahrenheit_temp;
	double converted_to_celsius = fahrenheit_to_celsius(fahrenheit_temp);
	cout << "The temperature in Celsius is " << converted_to_celsius;

	#ifdef DEBUG
		debug_message();
	#endif


	return 0;
}
