#include <iostream>
#include <cmath>  // For handling mathematical operations
#include <limits> // For handling invalid results
using namespace std;

// Function to handle division of integers
int divideInt(int a, int b) {
    if (b == 0) {
        cout << "Error: Division by zero is undefined for integers." << endl;
        return numeric_limits<int>::min();  // Return an error code (minimum integer)
    }
    return a / b;
}

// Function to handle division of doubles
double divideDouble(double a, double b) {
    if (b == 0.0) {
        cout << "Error: Division by zero is undefined for floating-point numbers." << endl;
        return numeric_limits<double>::quiet_NaN();  // Return NaN (not-a-number) for floating point division by zero
    }
    return a / b;
}

// Function to operate on two integers with a pointer to a function
int operate(int a, int b, int (operation)(int, int)) {
    return operation(a, b);  // Perform the operation and return the result
}

// Function to operate on two doubles with a pointer to a function
double operate(double a, double b, double (operation)(double, double)) {
    return operation(a, b);  // Perform the operation and return the result
}

int main() {
    int x, y;   // Variables for integer input
    double p, q; // Variables for double input

    cout << "Enter two integers (a and b): ";
    cin >> x >> y;

    // Example of integer operations
    cout << "Operating on integers: " << x << " / " << y << " = " << operate(x, y, divideInt) << endl;

    cout << "Enter two doubles (p and q): ";
    cin >> p >> q;

    // Example of double operations
    cout << "Operating on doubles: " << p << " / " << q << " = " << operate(p, q, divideDouble) << endl;

    return 0;
}