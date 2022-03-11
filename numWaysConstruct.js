'use strict';

function numWaysConstruct(target, wordbank, memo = {}) {

    if (target in memo) {
        return memo[target];
    }

    if (target === '') {
        return 1;
    }

    let numWays = 0;

    for (let i = 0; i < wordbank.length; i++) {

        if (target.startsWith(wordbank[i])) {
            
            numWays += numWaysConstruct(target.slice(wordbank[i].length), wordbank, memo);
        }

        if (target.endsWith(wordbank[i])) {

            numWays += numWaysConstruct(target.slice(0, -wordbank[i].length), wordbank, memo);
        }
    }

    memo[target] = numWays;
    return memo[target];
};

console.log(numWaysConstruct('abcdef', ['ab', 'abc', 'cd', 'def', 'abcd'])); // true
console.log(numWaysConstruct('skateboard', ['bo', 'rd', 'ate', 't', 'boar'])); // false
console.log(numWaysConstruct('enterapotentpot', ['a', 'p', 'ent', 'enter', 'ot', 'o', 't'])); // true
console.log(numWaysConstruct('eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef', [
    'e',
    'ee',
    'eee',
    'eeee',
    'eeeee',
    'eeeeee'
])); // false