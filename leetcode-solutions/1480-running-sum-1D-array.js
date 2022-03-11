/**
 * @param {number[]} nums
 * @return {number[]}
 */
 var runningSum = function(nums) {
    
    function sum(nums, i) {

        if (i >= nums.length) {
            return;
        }

        nums[i] += nums[i - 1];

        sum(nums, i + 1);
    }
    
    sum(nums, 1);
    return nums;
};

// Time: O(n);
// Space: no additional space
