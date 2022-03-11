'use strict';

// merge sort should work for permutations as well in some sense, at least the division portion? till we revidive up
const mergeSort = (array, p, r) => {

    if (p < r) {

        var q = Math.floor((p + r) / 2);
        mergeSort(array, p, q);
        mergeSort(array, q + 1, r);
        merge(array, p, q, r);
    }
};

function merge(array, p, q, r) {

    var lowLength = q - p + 1;
    var highLength = r - q;

    var lowHalf = [];
    var highHalf = [];

    var i = 0, j = 0, k = p;

    for (k = p; k <= q; i++, k++) {
        lowHalf.push(array[k]);
    }

    for (k = q + 1; k <= r; j++, k++) {
        highHalf.push(array[k]);
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

let array = [3, 7, 12, 14, 2, 6, 9, 11];
console.log(`${array}:`);
mergeSort(array, 0, array.length - 1);
console.log(`sorted: ${array}`);

array = [99, 97, -3, -55, -6, 7, 8, 14, 31, 32, -0, 0, 3, 2];
console.log(`${array}:`);
mergeSort(array, 0, array.length - 1);
console.log(`sorted: ${array}`);
