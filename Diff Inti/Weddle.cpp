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

    /* Ensure n is a multiple of 6, as Weddle's Rule requires this */
    if (n % 6 != 0)
    {
        cout << "Number of sub intervals (n) must be a multiple of 6. Please restart the program and enter a valid value for n.";
        return 1;
    }

    /* Calculation */

    /* Finding step size */
    h = (b - a) / n;

    /* Finding Integration Value */
    for (int i = 0; i < n; i += 6)
    {
        float x0 = a + i * h;
        float x1 = x0 + h;
        float x2 = x1 + h;
        float x3 = x2 + h;
        float x4 = x3 + h;
        float x5 = x4 + h;
        float x6 = x5 + h;

        integration += (3 * h / 10) * (f(x0) + 5 * f(x1) + f(x2) + 6 * f(x3) + f(x4) + 5 * f(x5) + f(x6));
    }

    cout << endl
         << "Required value of integration is: " << integration;

    return 0;
}
