bool isPalindrome(int x){
    
    if (x < 0) {
        return false;
    }
    
    if (x == 0) {
        return true;
    }
    
    int numDigits = (int)floor(log10(x)) + 1;
    int msbShift = (int)pow(10, numDigits - 1);
    
    while (x > 0) {
        
        if (x / msbShift != x % 10) {
            return false;
        }
        
        x %= msbShift;
        x /= 10;
        msbShift /= 100;
    }
    
    return true;
};
