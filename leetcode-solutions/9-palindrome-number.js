/**
 * @param {number} x
 * @return {boolean}
 */
 var isPalindrome = function(x) {
    
    let r = 0, copy = 0, orig = x;

    while (x > 0) {
        
        r = x % 10;
        x -= r;
        x /= 10;
        copy *= 10;
        copy += r;
    }
    
    return (copy === orig);
};
