// cd output && csc ..\quick-sort.cs && .\quick-sort.exe & cd ..
using System;
using System.Collections.Generic;

class Program {
    static void Main() {

        var swap = (List<int> array, int i, int j) => {

            var temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        };

        var partition = (List<int> array, int p, int r) => {

            var q = p;

            for (int j = p; j <= r - 1; j++) {

                if (array[j] <= array[r]) {
                    swap(array, j, q);
                    q++;
                }
            }

            swap(array, r, q);
            return q;
        };

        Action<List<int>, int, int> quickSort = null;

        quickSort = (List<int> array, int p, int r) => {

            if (p < r) {

                var q = partition(array, p, r);
                
                quickSort(array, p, q - 1);
                quickSort(array, q + 1, r);
            }
        };

        var array = new List<int>() { 3, 7, 12, 14, 2, 6, 9, 11 };
        Console.Write("array: "); foreach (var i in array) { Console.Write($"{i}, "); } Console.WriteLine();
        quickSort(array, 0, array.Count - 1);
        Console.Write("sorted: "); foreach (var i in array) { Console.Write($"{i}, "); } Console.WriteLine();

        array = new List<int>() { 99, 97, -3, -55, -6, 7, 8, 14, 31, 32, -0, 0, 3, 2 };
        Console.Write("array: "); foreach (var i in array) { Console.Write($"{i}, "); } Console.WriteLine();
        quickSort(array, 0, array.Count - 1);
        Console.Write("sorted: "); foreach (var i in array) { Console.Write($"{i}, "); } Console.WriteLine();
    }
}