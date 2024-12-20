/* Program Fixed Point Iteration
Program to find the root of the equation x*x*x - 3x + 1 =0
by fixed point iteration method. phi(x) is obtained by
rewrite f(x) = 0 as x = phi(x), which is to be supplied.*/
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define phi(x) (3 * x - 1) / (x * x)
/*definition of the function phi(x) and it to be
changed accordingly */
int main()
{
    int k = 0;        // counts number of iterations
    float x1, x0;     // initial guess
    float eps = 1e-5; // error tolerance
    printf("\nEnter the initial guess x0: ");
    scanf("%f", &x0);
    x1 = x0;
    do
    {

        k++;
        x0 = x1;
        x1 = phi(x0);
    } while (fabs(x1 - x0) > eps);
    printf("One root is %8.5f obtained at %d th iteration ", x1, k);
}