// cd output && csc ..\is-palindrome.cs && .\is-palindrome.exe & cd ..

using System;

class Program {
    static void Main() {

        var isAlpha = (char c) => {
            
            var charCode = (int)c;
            
            return ((charCode >= 65 && charCode <= 90)
                || (charCode >= 97 && charCode <= 122));
        };
        
        var isNumeric = (char c) => {
            
            var charCode = (int)c;
            
            return (charCode >= 48 && charCode <= 57);
        };
        
        var toLower = (char c) => {
            
            var charCode = (int)c;
            
            if (charCode >= 65 && charCode <= 90) {
                
                return (char)(charCode + 32);
            }
            
            return c;
        };
        
        Func<string, int, int, bool> isPalindrome = null;

        isPalindrome = (string word, int start, int end) => {
            
            if (start > end) {
                
                return true;
            }
            
            var left = word[start];
            var right = word[end];
            
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

        var word = "rotor";
        Console.WriteLine($"{word}: {isPalindrome(word, 0, word.Length - 1)}");

        word = "motor";
        Console.WriteLine($"{word}: {isPalindrome(word, 0, word.Length - 1)}");

        word = "racecar";
        Console.WriteLine($"{word}: {isPalindrome(word, 0, word.Length - 1)}");
    }
}
