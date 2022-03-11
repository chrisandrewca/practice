// cd output && csc ..\power.cs && .\power.exe & cd ..

using System;

class Program {
    static void Main() {

        Func<double, double, double> power = null;

        power = (double x, double n) => {

            if (n == 0) {
                return 1;
            }

            if (n < 0) {
                return 1 / power(x, -n);
            }

            if (n % 2 != 0) {
                return x * power(x, n - 1);
            }

            return x * power(x, n / 2);
        };

        Console.WriteLine($"power(2, 2): {power(2, 2)}");
        Console.WriteLine($"power(3, 0): {power(3, 0)}");
        Console.WriteLine($"power(9, 1): {power(9, 1)}");
        Console.WriteLine($"power(3, -1): {power(3, -1)}");
    }
}
