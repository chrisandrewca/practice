'use strict';

function power(x, n) {

    if (n === 0) {
        return 1;
    }

    if (n < 0) {

        return 1 / power(x, -n);
    }

    if (n % 2 !== 0) {

        return x * power(x, n - 1);
    }

    return x * power(x, n / 2);
};

console.assert(power(3, 0), 1);
console.assert(power(3, 1), 3);
console.assert(power(3, 2), 9);
console.assert(power(3, -1), 1/3);
