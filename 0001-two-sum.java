import java.util.HashMap;

class Solution {
	public int[] twoSum(int[] nums, int target) {
		int[] result = new int[2];
		HashMap<Integer, Integer> expected = new HashMap<>(nums.length - 1);
		out: for (int i = 0; i < nums.length; i++) {
			if (expected.containsKey(nums[i])) {
				result[0] = expected.get(nums[i]);
				result[1] = i;
				break out;
			}
			expected.put(target - nums[i], i);
		}
		return result;
	}
}