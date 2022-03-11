'use strict';

const memo = {};

// Time: O(2n) => O(n), O(n) chain with pair at (n-1) nodes => O(2n), reduces to O(n)
// Space: O(n)
const fibonacci = (n) => {

    if (n in memo) {
        return memo[n];
    }

    if (n <= 2) {
        return 1;
    }

    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
};

console.log(`fibonacci 5: ${fibonacci(5)}`);
console.log(`fibonacci 7: ${fibonacci(7)}`);
console.log(`fibonacci 255: ${fibonacci(255)}`);
