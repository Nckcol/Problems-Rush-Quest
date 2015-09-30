// Task-31.CosSeriesExpansion.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

using namespace std;

double cCos(double x, double eps);
void test(string description, double x, double eps, double answer);

int main()
{

    test("pi/4", M_PI_4, 1, cos(M_PI_4));
    test("pi/4", M_PI_4, 0.1, cos(M_PI_4));
    test("pi/4", M_PI_4, 0.01, cos(M_PI_4));
    test("pi/2", M_PI_2, 0.01, cos(M_PI_2));
    test("-pi/4", -M_PI_4, 0.01, cos(-M_PI_4));
    test("pi/3.9", M_PI / 3.9, 0.01, cos(M_PI / 3.9));
    test("0.1", 0.1, 0.01, cos(0.1));
    test("0.32", 0.32, 0.01, cos(0.32));
    test("-0.11", -0.11, 0.01, cos(-0.11));
    test("0.222", 0.222, 0.01, cos(0.222));
    test("-0.05", -0.05, 0.01, cos(-0.05));
    test("0", 0, 0.01, cos(0));
    test("100000000", 100000000, 0.01, cos(100000000));

    return 0;
}

double cCos(double x, double eps)
{
    x = fmod(x, 2 * M_PI);

    if (x > M_PI / 4 || x < -M_PI / 4)
        return 2 * pow(cCos(x / 2, eps), 2) - 1;

    double  value = 0,
        currentMemberValue = 0,
        previousMemberValue = 0,
        xPow = 1;
    int     factorial = 1,
        sign = 1;

    int i = 1;

    do
    {
        previousMemberValue = currentMemberValue;
        currentMemberValue = sign*xPow / factorial;

        value += currentMemberValue;

        xPow *= x*x;
        factorial *= i;
        factorial *= i + 1;
        i += 2;
        sign *= -1;
    } while (fabs(currentMemberValue - previousMemberValue) >= eps);

    return value;
}

void test(string description, double x, double eps, double answer)
{
    bool passed = false;

    if ((answer != answer) && cCos(x, eps) != cCos(x, eps)) passed = true;
    if (fabs(answer - cCos(x, eps) < eps)) passed = true;

    cout << "x = " << description << " cos(x) = " << cCos(x, eps) << " " << (passed ? "PASSED" : "FAILED") << endl;
}