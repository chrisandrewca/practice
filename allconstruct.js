'use strict';

function allConstruct(target, wordbank, memo = {}, err = true) {

    if (target in memo) {

        return memo[target];
    }

    if (target === '') {

        return [[]];
    }

    let ways = [];

    for (let word of wordbank) {

        if (target.indexOf(word) === 0) {

            //console.log({ suffix: target.slice(word.length) });
            const suffix = target.slice(word.length);
            const suffixes = allConstruct(suffix, wordbank, memo, false);
            //console.log({ halfMeasures: suffixes });
            const targets = suffixes.map(s => [word, ...s]);
            ways.push(...targets);
            console.log({ ways });
        }
    }

    // for (let i = 0; i < wordbank.length; i++) {

    //     if (target.startsWith(wordbank[i])) {

    //         //console.log({ suffix2: target.slice(wordbank[i].length) });
    //         let halfMeasures = allConstruct(target.slice(wordbank[i].length), wordbank, memo, false);
    //         //console.log({ halfMeasures2: halfMeasures });
    //         halfMeasures.map(hm => {
    //             hm.unshift(wordbank[i]);
    //             ways.push(hm);
    //             return hm;
    //         });
    //         console.log({ ways });
    //     }
    // }

    // for (let i = 0; i < wordbank.length; i++) {

    //     if (target.startsWith(wordbank[i])) {

    //         let halfMeasures = allConstruct(target.slice(wordbank[i].length), wordbank, memo);
    //         halfMeasures.map(halfMeasure => {
    //             halfMeasure.unshift(wordbank[i]);
    //             ways.push(halfMeasure);
    //             return halfMeasure;
    //         });
    //     }

    //     // if (target.endsWith(wordbank[i])) {

    //     //     let halfMeasures = allConstruct(target.slice(0, -wordbank[i].length), wordbank, memo);
    //     //     halfMeasures.map(halfMeasure => {
    //     //         halfMeasure.unshift(wordbank[i]);
    //     //         ways.push(halfMeasure);
    //     //         return halfMeasure;
    //     //     });
    //     // }
    // }

    memo[target] = ways;
    return memo[target];
};

console.log(allConstruct('abcdef', ['ab', 'abc', 'cd', 'def', 'abcd'])); // true
console.log(allConstruct('skateboard', ['bo', 'rd', 'ate', 't', 'boar'])); // false
console.log(allConstruct('enterapotentpot', ['a', 'p', 'ent', 'enter', 'ot', 'o', 't'])); // true
console.log(allConstruct('eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef', [
    'e',
    'ee',
    'eee',
    'eeee',
    'eeeee',
    'eeeeee'
])); // false