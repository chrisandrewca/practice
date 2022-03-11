'use strict';

function canConstruct(target, wordBank, memo = {}) {

    if (target in memo) {
        return memo[target];
    }

    if (target === '') {
        return true;
    }

    for (let i = 0; i < wordBank.length; i++) {

        if (target.startsWith(wordBank[i])) {

            const nextTarget = target.slice(wordBank[i].length);
            //console.log({ startsWith: { target, nextTarget } });

            if (canConstruct(nextTarget, wordBank, memo)) {

                memo[target] = true;
            }
        }

        if (target.endsWith(wordBank[i])) {

            const nextTarget = target.slice(0, -wordBank[i].length);
            //console.log({ endsWith: { target, nextTarget } });

            if (canConstruct(nextTarget, wordBank, memo)) {

                memo[target] = true;
            }
        }

        if (target in memo && memo[target]) {
            return memo[target];
        }
    }

    memo[target] = false;
    return false;
};

console.log(canConstruct('abcdef', ['ab', 'abc', 'cd', 'def', 'abcd'])); // true
console.log(canConstruct('skateboard', ['bo', 'rd', 'ate', 't', 'boar'])); // false
console.log(canConstruct('enterapotentpot', ['a', 'p', 'ent', 'enter', 'ot', 'o', 't'])); // true
console.log(canConstruct('eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef', [
    'e',
    'ee',
    'eee',
    'eeee',
    'eeeee',
    'eeeeee'
])); // false