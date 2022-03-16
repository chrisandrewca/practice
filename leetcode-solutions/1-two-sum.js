/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
 var twoSum = function(nums, target) {

    function findTwoSum(nums, target, i, memo = new Map()) {
        
        if (i >= nums.length) {
            return [];
        }
        
        const remainder = target - nums[i];
        if (memo.has(remainder)) {
            return [memo.get(remainder), i];
        }
        
        memo.set(nums[i], i);

        return findTwoSum(nums, target, i + 1, memo);
    }
    
    return findTwoSum(nums, target, 0);
};
