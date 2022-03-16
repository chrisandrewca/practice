// cl /W4 /EHsc /TP /Zc:preprocessor merge-sort.cpp /Fo.\output\ /Fe.\output\ /link && .\output\merge-sort.exe

#include <functional>
#include <iostream>
#include <vector>
using namespace std;

void main() {

    cout << (int)1.9 << endl;

    function<void(vector<int>&, int, int)> mergeSort;
    function<void(vector<int>&, int, int, int)> merge;

    mergeSort = [&mergeSort, &merge](vector<int>& array, int p, int r) {

        if (p < r) {

            auto q = (p + r) / 2;

            mergeSort(array, p, q);
            mergeSort(array, q + 1, r);
            merge(array, p, q, r);
        }
    };

    merge = [](vector<int>& array, int p, int q, int r) {

        auto lowLength = q - p + 1;
        auto highLength = r - q;

        vector<int> lowHalf;
        vector<int> highHalf;

        int i = 0, j = 0, k = p;

        for (; k <= q; i++, k++) {
            lowHalf.push_back(array[k]);
        }

        for (; k <= r; j++, k++) {
            highHalf.push_back(array[k]);
        }

        i = 0, j = 0, k = p;

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

    vector<int> array = { 3, 7, 12, 14, 2, 6, 9, 11 };
    cout << "array: "; for (auto i : array) { cout << i << ", "; } cout << endl;
    mergeSort(array, 0, (int)array.size() - 1);
    cout << "sorted: "; for (auto i : array) { cout << i << ", "; } cout << endl;

    array = { 99, 97, -3, -55, -6, 7, 8, 14, 31, 32, -0, 0, 3, 2 };
    cout << "array: "; for (auto i : array) { cout << i << ", "; } cout << endl;
    mergeSort(array, 0, (int)array.size() - 1);
    cout << "sorted: "; for (auto i : array) { cout << i << ", "; } cout << endl;
};
