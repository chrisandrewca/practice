'use strict';

function howSum(targetSum, numbers, memo = {}) {

    if (targetSum in memo) {
        return memo[targetSum];
    }

    if (targetSum === 0) {
        return [];
    } else if (targetSum < 0) {
        return null;
    }

    for (let i = 0; i < numbers.length; i++) {

        const how = howSum(targetSum - numbers[i], numbers, memo);

        if (how !== null) {

            memo[targetSum] = [...how, numbers[i]];
            return memo[targetSum];
        }
    }

    memo[targetSum] = null;
    return null;
};

console.log(howSum(7, [2, 3, 8]));
console.log(howSum(7, [2, 4]));
console.log(howSum(7, [5, 3, 4, 7]));
console.log(howSum(2, [2, 0]));
console.log(howSum(300, [7, 14]));
console.log(howSum(500, [2]));
