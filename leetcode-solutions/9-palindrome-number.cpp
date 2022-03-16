class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0) {
            return false;
        }
        
        if (x == 0) {
            return true;
        }

        // gets you the number of digits in number x
        int numDigits = (int)floor(log10(x)) + 1;

        int msbShift = (int)pow(10, numDigits - 1);

        while (x > 0) {
            if (x / msbShift != x % 10) {
                return false;
            }
            
            x %= msbShift; // drop digit on left
            x /= 10; // drop digit on right
            msbShift /= 100;
        }

        return true;
    }
};
