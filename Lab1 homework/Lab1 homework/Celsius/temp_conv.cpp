#include "../temp_conv.h"
using namespace std;


double celsius_to_fahrenheit(double celsius) {
	return (celsius * 9.0 / 5.0) + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
	return (fahrenheit - 32.0) * 5 / 9;
}
	