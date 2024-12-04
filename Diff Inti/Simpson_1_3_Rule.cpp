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

    /* Ensure n is even, as Simpson's 1/3 Rule requires an even number of subintervals */
    if (n % 2 != 0)
    {
        cout << "Number of sub intervals (n) must be even. Please restart the program and enter an even value for n.";
        return 1;
    }

    /* Calculation */

    /* Finding step size */
    h = (b - a) / n;

    // I= h/3[f(a)+4∑f(xi)+2∑f(xi)+f(b)]  // i odd 4, i even 2
    /* Finding Integration Value */
    integration = f(a) + f(b);

    for (int i = 1; i < n; i++)
    {
        float x = a + i * h;
        if (i % 2 == 0) // For even indices
            integration = integration + 2 * f(x);
        else // For odd indices
            integration = integration + 4 * f(x);
    }

    integration = integration * h / 3; // Apply Simpson's 1/3 Rule formula

    cout << endl
         << "Required value of integration is: " << integration;

    return 0;
}
