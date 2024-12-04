#include <iostream>
#include <cmath>

/* Define function here */
#define f(x) 1 / (1 + pow(x, 2))

using namespace std;

int main()
{
    float a, b, h, integration = 0.0, x;
    int n;

    /* Input */
    cout << "Enter lower limit of integration (a): ";
    cin >> a;
    cout << "Enter upper limit of integration (b): ";
    cin >> b;
    cout << "Enter number of sub intervals (n): ";
    cin >> n;

    /* Calculation */
    // I= 2h[f(a)+2∑f(xi)+f(b)]
    /* Finding step size */
    h = (b - a) / n;

    /* Finding Integration Value */
    integration = f(a) + f(b);

    for (int i = 1; i <= n - 1; i++)
    {
        x = a + i * h; // Calculate intermediate points
        integration = integration + 2 * f(x);
    }

    integration = integration * h / 2; // Apply the Trapezoidal Rule

    cout << endl
         << "Required value of integration is: " << integration;

    return 0;
}
