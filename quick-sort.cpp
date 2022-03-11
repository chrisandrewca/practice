// cl /W4 /EHsc quick-sort.cpp /Fo.\output\ /Fe.\output\ /link && .\output\quick-sort.exe

#include <functional>
#include <iostream>
#include <vector>
using namespace std;

void main() {

    auto swap = [](vector<int>& array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    };

    function<void(vector<int>&, int, int)> quickSort;
    function<int(vector<int>&, int, int)> partition;

    quickSort = [&quickSort, &partition](vector<int>& array, int p, int r) {

        if (p < r) {

            int q = partition(array, p, r);

            quickSort(array, p, q - 1);
            quickSort(array, q + 1, r);
        }
    };

    partition = [&swap](vector<int>& array, int p, int r) {

        int q = p;

        for (int j = p; j <= r - 1; j++) {

            if (array[j] <= array[r]) {
                swap(array, j, q);
                q++;
            }
        }

        swap(array, r, q);
        return q;
    };


    vector<int> array = { 3, 7, 12, 14, 2, 6, 9, 11 };
    cout << "array: "; for (auto i : array) { cout << i << ", "; } cout << endl;
    quickSort(array, 0, (int)array.size() - 1);
    cout << "sorted: "; for (auto i : array) { cout << i << ", "; } cout << endl;

    array = { 99, 97, -3, -55, -6, 7, 8, 14, 31, 32, -0, 0, 3, 2 };
    cout << "array: "; for (auto i : array) { cout << i << ", "; } cout << endl;
    quickSort(array, 0, (int)array.size() - 1);
    cout << "sorted: "; for (auto i : array) { cout << i << ", "; } cout << endl;
};
