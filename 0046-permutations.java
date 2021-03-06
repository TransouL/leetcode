class Solution {
	List<List<Integer>> result = new ArrayList<List<Integer>>();
	List<Integer> current = new ArrayList<Integer>();
	boolean[] flag = null;

	public List<List<Integer>> permute(int[] nums) {
		flag = new boolean[nums.length];
		dfs(0, nums);
		return result;
	}

	private void dfs(int steps, int[] nums) {
		if (steps == nums.length) {
			result.add(new ArrayList<Integer>(current));
			return;
		}
		for (int i = 0; i < nums.length; i++) {
			if (!flag[i]) {
				current.add(nums[i]);
				flag[i] = true;
				dfs(steps + 1, nums);
				current.remove(current.size() - 1);
				flag[i] = false;
			}
		}
	}
}