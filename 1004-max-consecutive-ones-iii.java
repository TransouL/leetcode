public class Solution {
	public int longestOnes(int[] A, int K) {
		int result = 0;
		int left = 0, right = 0;
		int zeroCount = 0;
		do {
			if (A[right] == 0)
				zeroCount++;
			while (zeroCount > K) {
				if (A[left++] == 0)
					zeroCount--;
			}
			if (result < right - left + 1) {
				result = right - left + 1;
			}
		} while (++right < A.length);
		return result;
	}
}