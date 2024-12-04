// Program to find derivative using Newton Backward Difference Method
#include <iostream>

using namespace std;

int main() {
    int n;
    double x[20], y[20][20], xp, h, derivative;
    
    // Input number of data points
    cout << "Enter number of data points: ";
    cin >> n;
    
    // Input x values
    cout << "Enter x values:\n";
    for(int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
    }
    
    // Input corresponding y values
    cout << "Enter corresponding y values:\n";
    for(int i = 0; i < n; i++) {
        cout << "y[" << i << "] = ";
        cin >> y[i][0];
    }
    
    // Calculate backward differences
    for(int i = 1; i < n; i++) {
        for(int j = n - 1; j >= i; j--) {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }
    
    // Display backward difference table
    cout << "\nBackward Difference Table:\n";
    for(int i = 0; i < n; i++) {
        cout << x[i];
        for(int j = 0; j <= i; j++) {
            cout << "\t" << y[i][j];
        }
        cout << endl;
    }
    
    // Input the value of x for which derivative is required
    cout << "\nEnter the value of x for which you want the derivative: ";
    cin >> xp;
    
    // Calculate step size
    h = x[1] - x[0];
    
    // Calculate p
    double p = (xp - x[n - 1]) / h;
    
    // Calculate derivative using Newton Backward Difference formula
    derivative = y[n - 1][1];
    double factorial = 1;
    for(int i = 2; i < n; i++) {
        factorial *= i;
        double term = y[n - 1][i] * (p + i - 1);
        derivative += term;
    }
    derivative /= h;
    
    // Display the result
    cout << "\nThe derivative at x = " << xp << " is " << derivative << endl;
    
    return 0;
}