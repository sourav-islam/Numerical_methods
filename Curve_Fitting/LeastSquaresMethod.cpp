#include <iostream>
#include <vector>
using namespace std;

void leastSquares(const vector<double> &x, const vector<double> &y, double &a, double &b)
{
    int n = x.size();
    double sum_x = 0, sum_y = 0, sum_xy = 0, sum_xx = 0;

    for (int i = 0; i < n; i++)
    {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_xx += x[i] * x[i];
    }

    a = (n * sum_xy - sum_x * sum_y) / (n * sum_xx - sum_x * sum_x);
    b = (sum_y - a * sum_x) / n;
}

int main()
{
    vector<double> x = {0, 1, 2, 3, 4};         // 1, 2, 3, 4
    vector<double> y = {1, 1.8, 3.3, 4.5, 6.3}; // 2, 3, 5, 5
    double a, b;
    leastSquares(x, y, a, b);
    cout << "Best fit line: y = " << a << "x + " << b << endl;
    return 0;
}
