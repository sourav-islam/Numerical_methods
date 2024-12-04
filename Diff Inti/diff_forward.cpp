#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    double x[20], y[20][20];

    // Input data points
    cout << "Enter the values of x and corresponding y:\n";
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i][0];
    }

    double h = x[1] - x[0]; // Assuming equal intervals

    // Calculating forward differences
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    double x0;
    cout << "Enter the value of x at which you want to find the derivative: ";
    cin >> x0;

    double p = (x0 - x[0]) / h;

    // Calculating the derivative using Newton's forward formula
    double derivative = y[0][1] / h;

    cout << "The approximate value of the derivative at x = " << x0 << " is " << derivative << endl;

    return 0;
}