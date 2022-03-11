// cd output && csc ..\merge-sort.cs && .\merge-sort.exe & cd ..
using System;
using System.Collections.Generic;

class Program {
    static void Main() {

        Action<List<int>, int, int> mergeSort = null;
        Action<List<int>, int, int, int> merge = null;

        mergeSort = (List<int> array, int p, int r) => {

            if (p < r) {

                int q = (p + r) / 2;

                mergeSort(array, p, q);
                mergeSort(array, q + 1, r);
                merge(array, p, q, r);
            }
        };

        merge = (List<int> array, int p, int q, int r) => {

            var lowLength = q - p + 1;
            var highLength = r - q;

            var lowHalf = new List<int>();
            var highHalf = new List<int>();

            int i = 0, j = 0, k = p;

            for (; k <= q; i++, k++) {
                lowHalf.Add(array[k]);
            }

            for (; k <= r; j++, k++) {
                highHalf.Add(array[k]);
            }

            i = 0;
            j = 0;
            k = p;

            while (i < lowLength && j < highLength) {

                if (lowHalf[i] <= highHalf[j]) {
                    array[k] = lowHalf[i];
                    i++;
                } else {
                    array[k] = highHalf[j];
                    j++;
                }

                k++;
            }

            while (i < lowLength) {
                array[k] = lowHalf[i];
                i++;
                k++;
            }

            while (j < highLength) {
                array[k] = highHalf[j];
                j++;
                k++;
            }
        };

        var array = new List<int>() { 3, 7, 12, 14, 2, 6, 9, 11 };
        Console.Write("array: "); foreach (var i in array) { Console.Write($"{i}, "); } Console.WriteLine();
        mergeSort(array, 0, array.Count - 1);
        Console.Write("sorted: "); foreach (var i in array) { Console.Write($"{i}, "); } Console.WriteLine();

        array = new List<int>() { 99, 97, -3, -55, -6, 7, 8, 14, 31, 32, -0, 0, 3, 2 };
        Console.Write("array: "); foreach (var i in array) { Console.Write($"{i}, "); } Console.WriteLine();
        mergeSort(array, 0, array.Count - 1);
        Console.Write("sorted: "); foreach (var i in array) { Console.Write($"{i}, "); } Console.WriteLine();
    }
}
