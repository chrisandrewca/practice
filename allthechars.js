'use strict';

// function allTheCharsWhichWays(word, maxK, memo = {}) {
// }


// console.log(allTheCharsWhichWay('123', '123'.length));


function getPermutations(arr) {

    const output = [];

    function swap(arr, i, j) {
        let temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    };

    function generate(n, arr) {

        if (n === 1) {
            output.push(arr.slice());
            return;
        }

        generate(n - 1, arr);

        for (let i = 0; i < n - 1; i++) {

            if (n % 2 === 0) {

                swap(arr, i, n - 1);
            } else {
                swap(arr, 0, n - 1);
            }

            generate(n - 1, arr);
        }
    };

    generate(0, arr);

    return output;
};

console.log(getPermutations([1, 2, 3]));
