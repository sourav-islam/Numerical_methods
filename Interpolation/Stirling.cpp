#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double stirlingInterpolation(vector<double> x, vector<double> y, double val) {
    int n = x.size();
    vector<vector<double>> delta(n, vector<double>(n));

    for (int i = 0; i < n; i++)
        delta[i][0] = y[i];

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++)
            delta[i][j] = delta[i + 1][j - 1] - delta[i][j - 1];
    }

    int mid = n / 2;
    double h = x[1] - x[0];
    double u = (val - x[mid]) / h;
    double result = y[mid];
    double term = u;

    for (int i = 1; i < n; i++) {
        if (i % 2 == 0)
            result += term * delta[mid - i / 2][i];
        else
            result += term * delta[mid - (i - 1) / 2][i];
        term *= (u * u - (i * i)) / ((i + 1) * 2);
    }

    return result;
}

int main() {
    vector<double> x = {0, 1, 2, 3, 4};
    vector<double> y = {1, 2, 4, 8, 16};
    double val = 2.5;
    cout << "Interpolated value: " << stirlingInterpolation(x, y, val) << endl;
    return 0;
}
