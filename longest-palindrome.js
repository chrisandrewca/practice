// /**
//  * @param {string} s
//  * @return {number}
//  */
//  var longestPalindrome = function(s) {

//     let memo = {}; // share memo across roots

//     // optimize palindrome later?
//     function pickLetter(i, s) {
        
//         if (i === s.length - 1) {

//             return s[i];
//         }
        
//         // at every level we need to hop around and try each node, and then.. hop around from that node, etc
//         for (let j = 0; j < s.length; j++) {
            
//             if (j !== i) {
                
//                 let current = memo[s[i]]; // memo key has to iteratively get bigger
//                 current += pickLetter(j, s);
//                 memo[current] = ???;
//             }
//         }

//         return pickLetter(i + 1, s);
//     };
    
//     for (let i = 0; i < s.length; i++) {

//         pickLetter(i, s);
//     }
// };

/**
 * @param {string} s
 * @return {boolean}
 */
 var isPalindrome = function(letters) {
    
    function isNumeric(charCode) {
        
        return (charCode >= 48 && charCode <= 57);
    }
    
    function isAlpha(charCode) {
        return ((charCode >= 65 && charCode <= 90)
                || (charCode >= 97 && charCode <= 122));
    }
    
    function toLower(charCode) {
        
        if (charCode >= 65 && charCode <= 90) {
            return charCode + 32;
        }
        
        return charCode;
    }

    function checkPalindrome(letters, start, end) {

        if (start > end) {
            return true;
        }
        
        let leftCode = letters.charCodeAt(start);
        let rightCode = letters.charCodeAt(end);
        
        leftCode = toLower(leftCode);
        rightCode = toLower(rightCode);

        if (!(isAlpha(leftCode) || isNumeric(leftCode))) {
            return checkPalindrome(letters, ++start, end);
        }
        
        if (!(isAlpha(rightCode) || isNumeric(rightCode))) {
            return checkPalindrome(letters, start, --end);
        }

        if (leftCode !== rightCode) {
            return false;
        }
        
        return checkPalindrome(letters, ++start, --end);
    }
    
    return checkPalindrome(letters, 0, letters.length - 1);
};
