#include <iostream>
#include <cmath>

using namespace std;

// Function for which we are finding the root
double f(double x) {
    return x * x - 2; // Example: root at sqrt(2)
}

// Steffensen's method implementation
double steffensen(double x0, double tol) {
    double x = x0;
    int i = 0;
    while (abs(f(x)) >= tol){
        i++;
        double fx = f(x);
        double f1 = f(x + fx);
        double denominator = f1 - fx;
        if(denominator == 0){
            cout << "Division by zero encountered." << endl;
            return x;
        }
        double x_new = x - (fx * fx) / denominator;
        x = x_new;
    }
    return x;
}

int main(){
    double initial_guess;
    double tolerance=0.0001;

    cout << "Enter initial guess: ";
    cin >> initial_guess;

    double root = steffensen(initial_guess, tolerance);
    cout << "Approximate root: " << root << endl;

    return 0;
}