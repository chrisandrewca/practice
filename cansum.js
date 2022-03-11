'use strict';

function canSum(targetSum, numbers, memo = {}) {

    // need in since falsy
    if (targetSum in memo) return memo[targetSum];

    if (targetSum === 0) {
        return true;
    } else if (targetSum < 0) {
        return false;
    }

    for (let i = 0; i < numbers.length; i++) {

        let canCanSum = canSum(targetSum - numbers[i], numbers, memo);

        if (canCanSum) {

            memo[targetSum] = true;
            return true;
        }
    }

    memo[targetSum] = false;
    return false;
}

console.log(canSum(7, [2, 3, 8]));
console.log(canSum(7, [2, 4]));
console.log(canSum(7, [5, 3, 4, 7]));
console.log(canSum(2, [2, 0]));
console.log(canSum(300, [7, 14]));
console.log(canSum(500, [2]));