'use strict';

const quickSort = (array, p, r) => {

    if (p < r) {
        
        var q = partition(array, p, r);
        
        quickSort(array, p, q - 1);
        quickSort(array, q + 1, r);
    }
};

function partition(array, p, r) {

    let q = p;

    for (let j = p; j <= r - 1; j++) {
        if (array[j] <= array[r]) {
            swap(array, j, q);
            q++;
        }
    }

    swap(array, r, q);
    return q;
};

function swap(array, i, j) {
    const temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

let array = [3, 7, 12, 14, 2, 6, 9, 11];
console.log(`${array}:`);
quickSort(array, 0, array.length - 1);
console.log(`sorted: ${array}`);

array = [99, 97, -3, -55, -6, 7, 8, 14, 31, 32, -0, 0, 3, 2];
console.log(`${array}:`);
quickSort(array, 0, array.length - 1);
console.log(`sorted: ${array}`);
