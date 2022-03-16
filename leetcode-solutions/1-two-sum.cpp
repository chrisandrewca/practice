class Solution {
    vector<int> findTwoSum(vector<int>& nums, int target, int i, map<int, int>& memo) {
        
        if (i >= nums.size()) {
            return vector<int>();
        }
        
        int remainder = target - nums[i];
        if (memo.find(remainder) != memo.end()) {
            return vector<int> { memo[remainder], i };
        }
        
        memo[nums[i]] = i;
        return findTwoSum(nums, target, i + 1, memo);
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> memo;
        return findTwoSum(nums, target, 0, memo);
    }
};
