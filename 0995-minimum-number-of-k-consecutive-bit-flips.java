public class Solution {
	public int minKBitFlips(int[] A, int K) {
		int n = A.length;
		// 差分数组   下标最多取到n，所以长度需要n+1
		int[] diff = new int[n + 1];
		int result = 0;
		int flipCount = 0;
		// 从左到右地执行这些翻转操作
		for (int i = 0; i < n; ++i) {
			// 通过累加差分数组可以得到，把当前位置之前全部翻成1，当前位置需要(已经)被翻转的次数
			flipCount += diff[i];
			// 判断当前位置(之前全部翻成1的情况下)是否是1，不是就要再翻一次
			if ((A[i] + flipCount) % 2 == 0) {
				// 如果后面已经不够K个来一起翻一次了
				if (i + K > n) {
					return -1;
				}
				++result;
				// 这里应该是diff[i]需要+1，然后也要累加给flipCount。但是diff[i]后面已经不用了，所以不更新了
				++flipCount;
				// 差分数组 值可能为负
				--diff[i + K];
			}
		}
		return result;
	}

	public static void main(String args[]) {
		Solution s = new Solution();
		int[] A = { 0, 1, 0 };
		System.out.println(s.minKBitFlips(A, 1));
		int[] A2 = { 1, 1, 0 };
		System.out.println(s.minKBitFlips(A2, 2));
		int[] A3 = { 0, 0, 0, 1, 0, 1, 1, 0 };
		System.out.println(s.minKBitFlips(A3, 3));
	}
}