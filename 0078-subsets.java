public class Solution {
	public static List<List<Integer>> subsets(int[] nums) {
		List<List<Integer>> result = new ArrayList<>();
		result.add(new ArrayList<>());
		for (int i = 0; i < nums.length; i++) {
			int currentSize = result.size();
			for (int j = 0; j < currentSize; j++) {
				List<Integer> tmp = new ArrayList<>(result.get(j));
				tmp.add(nums[i]);
				result.add(tmp);
			}
		}
		return result;
	}
}