#include <iostream>
#include <cmath>
using namespace std;

// Function for which we want to find the root
double f(double x) {
    return x * x - 4;
}

// First derivative of the function
double f_prime(double x) {
    return 2 * x;
}

// Second derivative of the function
double f_double_prime(double x) {
    return 2;
}

// Halley's method to find the root
double halley(double x, double tol) {
    double h;
    // Continue iterating until the function value is within the tolerance
    while (fabs(f(x)) >= tol) {
        // Calculate the Halley update
        h = (2 * f(x) * f_prime(x)) / (2 * pow(f_prime(x), 2) - f(x) * f_double_prime(x));
        // Update the current guess
        x = x - h;
    }
    return x;
}

int main() {
    double ititial_guess = 5;       // Initial guess
    double tol = 0.0001; // Tolerance for stopping
    double root = halley(ititial_guess, tol); // Find the root using Halley's method
    cout << "Root: " << root << endl; // Output the root
    return 0;
}
