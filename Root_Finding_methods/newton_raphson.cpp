/*#include <iostream>
#include <cmath>
using namespace std;

// Function for which we want to find the root
double f(double x) {
    return x * x - 4;
}

// Derivative of the function f(x)
double f_prime(double x) {
    return 2 * x;
}

// Newton-Raphson method to find the root
double newtonRaphson(double x0, double tol) {
    double h = f(x0) / f_prime(x0);
    while (fabs(h) >= tol) {
        h = f(x0) / f_prime(x0);
        x0 = x0 - h; // Update the guess
    }
    return x0;
}

int main() {
    double initialGuess = 5.0; // Starting point for the method
    double tolerance = 0.0001; // Desired accuracy
    double root = newtonRaphson(initialGuess, tolerance);
    cout << "Root: " << root << endl;
    return 0;
} */

// C++ program for implementation of Newton Raphson Method
// solving equations
#include <bits/stdc++.h>
#define EPSILON 0.001
using namespace std;
// Newton Raphson Method. The function is x^3 - x^2 + 2
double func(double x)
{
    return x * x * x - x * x + 2;
}
// Derivative of the above function which is 3*x^x - 2*x
double derivFunc(double x)
{
    return 3 * x * x - 2 * x;
}
// Function to find the root
void newtonRaphson(double x)
{
    double h = func(x) / derivFunc(x);
    while (abs(h) >= EPSILON)
    {
        h = func(x) / derivFunc(x);

        // x(i+1) = x(i) - f(x) / f'(x)
        x = x - h;
    }
    cout << "The value of the root is : " << x;
}
int main()
{
    double x0 = -20; // Initial values assumed
    newtonRaphson(x0);
    return 0;
}