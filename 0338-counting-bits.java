class Solution {
	public static int[] countBits(int num) {
		int[] result = new int[num + 1];
		if (num == 0) {
			return result;
		}
		result[1] = 1;
		for (int i = 2; i + 1 <= num; i += 2) {
			result[i] = result[i / 2];
			result[i + 1] = result[i] + 1;
		}
		if ((num & 1) == 0) {
			result[num] = result[num / 2];
		}
		return result;
	}
}