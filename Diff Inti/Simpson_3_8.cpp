#include <iostream>
#include <cmath>

/* Define function here */
#define f(x) 1 / (1 + pow(x, 2))

using namespace std;

int main()
{
    float a, b, h, integration = 0.0;
    int n;

    /* Input */
    cout << "Enter lower limit of integration (a): ";
    cin >> a;
    cout << "Enter upper limit of integration (b): ";
    cin >> b;
    cout << "Enter number of sub intervals (n): ";
    cin >> n;

    /* Ensure n is a multiple of 3, as Simpson's 3/8 Rule requires that */
    if (n % 3 != 0)
    {
        cout << "Number of sub intervals (n) must be a multiple of 3. Please restart the program and enter a valid value for n.";
        return 1;
    }

    /* Calculation */

    /* Finding step size */
    h = (b - a) / n;

    /* Finding Integration Value */
    integration = f(a) + f(b);
    // I= 3*h/8[f(a)+3∑f(xi)+2∑f(xi)+f(b)]  // if i
    for (int i = 1; i < n; i++)
    {
        float x = a + i * h;
        if (i % 3 == 0) // For every third index
            integration = integration + 2 * f(x);
        else // For other indices
            integration = integration + 3 * f(x);
    }

    integration = integration * (3 * h) / 8; // Apply Simpson's 3/8 Rule formula

    cout << endl
         << "Required value of integration is: " << integration;

    return 0;
}
