// cd output && csc ..\fibonacci.cs && .\fibonacci.exe & cd ..

using System;
using System.Collections.Generic;

class Program {
    static void Main() {

        Func<double, double> fibonacci = null;
        var memo = new Dictionary<double, double>();

        fibonacci = (double n) => {

            if (memo.ContainsKey(n)) {
                return memo[n];
            }

            if (n <= (double)2) {
                return (double)1;
            }

            memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
            return memo[n];
        };

        Console.WriteLine($"fibonacci 5: {fibonacci(5)}");
        Console.WriteLine($"fibonacci 7: {fibonacci(7)}");
        Console.WriteLine($"fibonacci 255: {fibonacci(255)}");
    }
}