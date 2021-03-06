class Solution {
	public int[] nextGreaterElements(int[] nums) {
		int[] result = new int[nums.length];
		Arrays.fill(result, -1);
		Stack<Integer> downStack = new Stack<>();
		for (int i = 0; i < nums.length; i++) {
			handle(nums, result, downStack, i);
		}
		for (int i = 0; i < nums.length - 1; i++) {
			handle(nums, result, downStack, i);
		}
		return result;
	}

	private void handle(int[] nums, int[] result, Stack<Integer> downStack, int i) {
		while (!downStack.isEmpty()) {
			int top = downStack.peek();
			if (nums[top] < nums[i]) {
				downStack.pop();
				result[top] = nums[i];
			} else {
				break;
			}
		}
		downStack.push(i);
	}
}