class Solution {
    
    void sum(vector<int>& nums, int i) {
        
        if (i >= nums.size()) {
            return;
        }
        
        nums[i] += nums[i - 1];
        sum(nums, i + 1);
    }
public:
    vector<int> runningSum(vector<int>& nums) {
        
        sum(nums, 1);
        return nums;
    }
};
