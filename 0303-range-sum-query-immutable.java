class NumArray {
	int[] sum = null;

	public NumArray(int[] nums) {
		if(nums.length == 0){
			return;
		}
		sum = new int[nums.length];
		int currentSum = 0;
		for (int i = 0; i < nums.length; i++) {
			currentSum += nums[i];
			sum[i] = currentSum;
		}
	}

	public int sumRange(int i, int j) {
		if(sum == null) {
			return 0;
		}
		if (i == 0) {
			return sum[j];
		} else {
			return sum[j] - sum[i - 1];
		}
	}
}