class Solution {
	public int[][] flipAndInvertImage(int[][] A) {
		int[][] result = new int[A.length][A[0].length];
		for (int i = 0; i < A.length; i++) {
			for (int j = 0; j <A[0].length; j++) {
				result[i][A[0].length - 1 - j] = A[i][j] ^ 1;
			}
		}
		return result;
	}
}