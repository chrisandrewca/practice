// cl /W4 /EHsc power.cpp /Fo.\output\ /Fe.\output\ /link && .\output\power.exe

#include <cmath>
#include <functional>
#include <iostream>

using namespace std;

void main() {

    function<double(double, double)> power;

    power = [&power](double x, double n) {

        if (n == 0) {
            return (double)1;
        }

        if (n < 0) {

            return (double)1 / power(x, -n);
        }

        if (fmod(n, 2) != 0) {

            return x * power(x, n - 1);
        }

        return x * power(x, n / 2);
    };

    cout << "power(2, 2): " << power(2, 2) << endl;
    cout << "power(3, 0): " << power(3, 0) << endl;
    cout << "power(9, 1): " << power(9, 1) << endl;
    cout << "power(3, -1): " << power(3, -1) << endl;
};
