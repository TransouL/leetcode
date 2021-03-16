class Solution {
	public int[][] matrixReshape(int[][] nums, int r, int c) {
		if(r * c != nums.length * nums[0].length) {
			return nums;
		}
        int[][] result = new int[r][c];
        for (int i = 0; i < nums.length; i++) {
			for (int j = 0; j < nums[0].length; j++) {
				int index = i * nums[0].length + j;
				result[index / c][index % c] = nums[i][j];
			}
		}
        return result;
    }
}