public class Solution {
    public bool IsPalindrome(int x) {
        
        if (x < 0) {
            return false;
        }
        
        if (x == 0) {
            return true;
        }
        
        var numDigits = (int)Math.Floor(Math.Log10(x)) + 1;
        var msbShift = (int)Math.Pow(10, numDigits - 1);
        
        while (x > 0) {
            
            if (x / msbShift != x % 10) {
                return false;
            }
            
            x %= msbShift;
            x /= 10;
            msbShift /= 100;
        }
        
        return true;
    }
}
