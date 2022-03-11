// cl /W4 /EHsc fibonacci.cpp /Fo.\output\ /Fe.\output\ /link && .\output\fibonacci.exe

#include <functional>
#include <iostream>
#include <map>

using namespace std;

void main() {

    function<double(double)> fibonacci;

    map<double, double> memo;

    fibonacci = [&fibonacci, &memo](double n) {

        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        if (n <= (double)2) {
            return (double)1;
        }

        memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return memo[n];
    };

    cout << "fibonacci 5: " << fibonacci(5) << endl;
    cout << "fibonacci 7: " << fibonacci(7) << endl;
    cout << "fibonacci 255: " << fibonacci(255) << endl;
};
