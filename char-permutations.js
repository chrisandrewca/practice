'use strict';

const memo = new Map();

const permutations = (i, maxK, word) => {

    // normalized values: A A
    // identity: array index or position
    // occurrence: identity + value

    // smallest sub-problem(s):
    // "choosing an occurence" - can we interpret our data in terms of occurrences?
    // putting that occurence in a unique position globally - define # of seats or k

    // the difference between one permutation and another is its order
    // can we somehow continously summarize the order using a higher order term so we don't need to compare each N that has been ordered for 2N comparisons
    // [A, A, B] => [A, B, A] => [A1, B, A2], [0, 2, 1] = 3 => [A1-0, B1-1, A2-2] = (1+0 + 1+1 + 2+2) = (1 + 2 + 4) = 7
    // [A, A, B] => [A, B, A] => [A2, B, A1], [1, 2, 0] = 3 => [A2-0, B1-1, A1-2], = (2+0 + 1+1 + 1+2) = (2 + 1 + 3) = 6 <- these are actual fucking identities! NOT lengths! HOLY SHIT
    // [B1-0, A1-1, A2-2] = (1+0 + 1+1 + 2+2) = 1 + 2 + 4 = 7
    // [B(66)1-0, A(65)1-1, A(65)2-2] = (66+1+0 + 65+1+1 + 65+2+2) = 203 // all position all the way down because ASCII 65 is a position
    // NEXT TRY: POSITION + INEQUALITY <

    // just an idea
    for (let i = 0; i < word.length; i++) {

        const occurrence = {
            i,
            value: word[i]
        };
    }

    // key sources:
    // word[i] => charCode
    // i
    // kth seat

    let code = word.charCodeAt(i);
    let position = i;
    let seat = k;
    let charIdentity = code + position + seat;

    let permutationIdentity = 0;
    permutationIdentity += charIdentity;

    // I'm pretty sure
    // - we can just store permutation identities and discard the data in some sense
    // - we can create base permutation identities and combine those to make all future permutations without any data
    // - we can potentially interpret any combined 'faux' identity and if not we can at least create any message/permutation within the bounds
    // of the structure created by the base identities
    memo.set(permutationIdentity, []);
    
    // perspective
    let base = word[i]; // is this iterative?

    // its all about maxk
    // because how do we know how many to pick?
    // this idea that we build up to maxk can be treated as implicit

    if (permutation.length === kSize) {

        if (memo.has(permutationIdentity)) {

            // i understand memoing lets of skip trees
            // but what do we do with returned permutations that we've already recorded?
            // set them again? lol check and dont set? wtf?
            return memo.get(permutationIdentity);
        }

        return permutation;
    }

    permutation(p + n, word.length - n, k - n);

    if (memo) return '';

    if (wordLength === 1) {

        return word[position];
    }

    // TODO explore language map features, which kind of objects can be used as a key?
    // hashmap interfaces:
    // C++: map<k, v> => where k is a sortable object or implements a comparison AKA do it yourself for composite keys
    // C#: same thing
    // JavaScript: by ref? obj, func, string
};

let word = 'abc';
console.log(`${word} ${permutations(start, bank)}`);