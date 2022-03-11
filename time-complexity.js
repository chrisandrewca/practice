'use strict';

// Time: O(n)
// Space: O(n)
const foo = (n) => {
    if (n <= 1) return;
    foo(n - 1);
};

// Time: O(n/2) => O(n)
// Space: O(n)
const bar = (n) => {
    if (n <= 1) return;
    foo(n - 2);
};

// Time: O(n^2)
// Space: O(n)
const dib = (n) => {

    if (n <= 1) {
        return;
    }

    dib(n - 1);
    dib(n - 1);
};

// Time: O(n^2) => O(n) w/ memo? probably not quite... MIT lecture
// Space: O(n)
const dib_memo = (n, dibCache = {}) => {

    if (dibCache[n]) {
        return;
    }

    if (n <= 1) {
        return;
    }

    dib_memo(n - 1, dibCache);
    dibCache[n] = 1;

    dib_memo(n - 1, dibCache);
};

let time = Date.now();

// console.log(dib(20));
// console.log(Date.now() - time);

time = Date.now();

console.log(dib_memo(250));
console.log(Date.now() - time);
