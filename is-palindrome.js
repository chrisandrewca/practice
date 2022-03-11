'use strict';

const isAlpha = (charCode) =>
    (charCode >= 65 && charCode <= 90)
    || (charCode >= 97 && charCode <= 122);

const isNumeric = (charCode) =>
    charCode >= 48 && charCode <= 57;

const toLower = (charCode) => {

    if (charCode >= 65 && charCode <= 90) {
        return charCode + 32;
    }

    return charCode;
};

const isPalindrome = (word, start, end) => {

    if (start > end) {

        return true;
    }

    let left = word.charCodeAt(start);
    let right = word.charCodeAt(end);

    if (!(isAlpha(left) || isNumeric(left))) {
        return isPalindrome(word, ++start, end);
    }

    if (!(isAlpha(right) || isNumeric(right))) {
        return isPalindrome(word, start, --end);
    }

    left = toLower(left);
    right = toLower(right);

    if (left !== right) {
        return false;
    }

    return isPalindrome(word, ++start, --end);
};

console.log(`${"rotor: "}${isPalindrome("rotor", 0, "rotor".length - 1)}`);
console.log(`${"motor: "}${isPalindrome("motor", 0, "motor".length - 1)}`);
console.log(`${"racecar: "}${isPalindrome("racecar", 0, "racecar".length - 1)}`);
