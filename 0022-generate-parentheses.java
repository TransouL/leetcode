class Solution {
	List<String> result = new ArrayList<String>();
	StringBuilder currentSB = new StringBuilder();

	public List<String> generateParenthesis(int n) {
		backtrack(n, 0, 0);
		return result;
	}

	private void backtrack(int n, int left, int right) {
		if (left == n && right == n) {
			result.add(currentSB.toString());
		}
		if(left < n) {
			currentSB.append('(');
			backtrack(n, left + 1, right);
			currentSB.deleteCharAt(currentSB.length() - 1);
		}
		if(right < n && left > right) {
			currentSB.append(')');
			backtrack(n, left, right + 1);
			currentSB.deleteCharAt(currentSB.length() - 1);
		}
	}
}