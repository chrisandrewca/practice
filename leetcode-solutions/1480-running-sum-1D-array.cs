public class Solution {
    
    private void Sum(int[] nums, int i) {
        
        if (i >= nums.Length) {

            return;
        }
        
        nums[i] += nums[i - 1];
        
        Sum(nums, i + 1);
    }

    public int[] RunningSum(int[] nums) {
        
        Sum(nums, 1);
        return nums;
    }
}
