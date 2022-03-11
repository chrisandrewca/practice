// cl /W4 /EHsc is-palindrome.cpp /Fo.\output\ /Fe.\output\ /link && .\output\is-palindrome.exe

#include <functional>
#include <iostream>

using namespace std;

void main() {

    auto isAlpha = [](int code) {

        return ((code >= 65 && code <= 90)
            || (code >= 97 && code <= 122));
    };

    auto isNumeric = [](int code) {

        return (code >= 48 && code <= 57);
    };

    auto toLower = [](int code) {

        if (code >= 65 && code <= 90) {

            return (char)(code + 32);
        }

        return (char)code;
    };

    function<bool(string, int, int)> isPalindrome;

    isPalindrome = [
        &isPalindrome,
        isAlpha,
        isNumeric,
        toLower](string word, int start, int end) {

        if (start > end) {

            return true;
        }

        auto left = word[start];
        auto right = word[end];

        if (!(isAlpha(left) || isNumeric(left))) {
            return isPalindrome(word, ++start, end);
        }

        if (!(isAlpha(right) || isNumeric(right))) {
            return isPalindrome(word, start, --end);
        }

        left = toLower(left);
        right = toLower(right);

        if (left != right) {
            return false;
        }

        return isPalindrome(word, ++start, --end);
    };

    string word = "rotor";
    cout << isPalindrome(word, 0, (int)(word.length() - 1)) << endl;

    word = "motor";
    cout << isPalindrome(word, 0, (int)(word.length() - 1)) << endl;

    word = "racecar";
    cout << isPalindrome(word, 0, (int)(word.length() - 1)) << endl;
};