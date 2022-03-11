'use strict';

function bestSum(targetSum, numbers, memo = {}) {

    if (targetSum in memo) {
        return memo[targetSum];
    }

    if (targetSum === 0) {
        return [];
    }

    if (targetSum < 0) {
        return null;
    }


    let shortestCombination = null;

    for (let i = 0; i < numbers.length; i++) {

        shortestCombination = bestSum(targetSum - numbers[i], numbers, memo);

        if (shortestCombination !== null) {

            if (targetSum in memo) {

                if (memo[targetSum].length > shortestCombination.length) {
                    memo[targetSum] = shortestCombination;
                }

            } else {
                memo[targetSum] = shortestCombination;
            }

            memo[targetSum].push(numbers[i]);
        }
    }

    memo[targetSum] = shortestCombination;
    return memo[targetSum];
}


console.log(bestSum(7, [5, 3, 4, 7]));
console.log(bestSum(7, [2, 3, 8]));
console.log(bestSum(7, [2, 4]));
console.log(bestSum(2, [2, 0]));
console.log(bestSum(300, [7, 14]));
console.log(bestSum(500, [2]));
