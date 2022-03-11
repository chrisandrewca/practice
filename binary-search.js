'use strict';

// requires array to be sorted, asc or desc
// here value is identity
function binarySearch(identity, array) {

    let min = 0;
    let max = array.length - 1;
    let i;

    while (min <= max) {

        i = Math.floor((min + max) / 2);

        if (identity < array[i]) {

            max = i - 1;
        } else if (identity > array[i]) {

            min = i + 1;
        } else if (identity === array[i]) {
            return i;
        }
    }

    return -1;
}

const primes = [
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
    41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97
];

console.assert(binarySearch(7, primes) === 3);
console.assert(binarySearch(89, primes) === primes.length - 2);
console.assert(binarySearch(-2, primes) === -1);
