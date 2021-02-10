class Solution {
    public int majorityElement(int[] nums) {
		int result = -1;
		int count = 0;

		for (int i = 0; i <= nums.length - 2; i += 2) {
			if (nums[i] != nums[i + 1]) {
				// do nothing
			} else {
				if (count == 0) {
					result = nums[i];
					count = 2;
				} else {
					if (result == nums[i]) {
						count += 2;
					} else {
						count -= 2;
					}
				}
			}
		}

		if (count == 0) {
			result = nums[nums.length - 1];
		}

		return result;
    }
}