class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int result = 0;
		int current = nums[0];
		for (int i = 1; i <= nums.length - 2; i++) {
			if(nums[i] == 1) {
				++ current;
			} else {
				if(result < current) {
					result = current;
				}
				if (result >= nums.length - i - 1) {
					return result;
				}
				current = 0;
			}
		}
		if(nums.length > 1 && nums[nums.length - 1] == 1) {
			return current + 1;
		} else {
			return current;
		}
    }
}