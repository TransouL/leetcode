class Solution {
	public static List<Integer> findDisappearedNumbers(int[] nums) {
		List<Integer> result = new ArrayList<Integer>();
		for (int currentIndex = 1; currentIndex <= nums.length; currentIndex++) {
			int currentValue = nums[currentIndex - 1];
			while(currentValue != nums[currentValue - 1]) {
				int preValue = currentValue;
				currentValue = nums[currentValue - 1];
				nums[preValue - 1] = preValue;
			}
		}
		
		for (int currentIndex = 1; currentIndex <= nums.length; currentIndex++) {
			if(nums[currentIndex - 1] != currentIndex ) {
				result.add(currentIndex);
			}
		}
		
		return result;
	}
}