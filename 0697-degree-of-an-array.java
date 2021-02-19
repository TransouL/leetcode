public class Solution {
	public int findShortestSubArray(int[] nums) {
		int[][] stats = new int[50001][3];
		for (int i = 0; i < nums.length; i++) {
			if (stats[nums[i]][0] == 0) {
				stats[nums[i]][0] = 1;
				stats[nums[i]][1] = i;
				stats[nums[i]][2] = i;
			} else {
				++stats[nums[i]][0];
				stats[nums[i]][2] = i;
			}
		}

		int maxCount = 0;
		int result = 0;
		for (int i = 0; i < stats.length; i++) {
			if (maxCount < stats[i][0]) {
				maxCount = stats[i][0];
				result = stats[i][2] - stats[i][1] + 1;
			} else if (maxCount == stats[i][0]) {
				maxCount = stats[i][0];
				if (result > stats[i][2] - stats[i][1] + 1) {
					result = stats[i][2] - stats[i][1] + 1;
				}
			}
		}
		return result;
	}
}