public class Solution {
	public int longestSubstring(String s, int k) {
		int n = s.length();
		int[] charCount = new int[26];
		for (int c : s.toCharArray())
			charCount[c - 'a']++;
		StringBuilder regex = new StringBuilder("[");
		boolean flag = true;
		for (int i = 0; i < 26; i++) {
			if (charCount[i] > 0 && charCount[i] < k) {
				regex.append("//");
				regex.append((char) ('a' + i));
			}
		}
		if (regex.length() == 1)
			return n;

		regex.append("]");
		String[] split = s.split(regex.toString());
		int result = 0;
		for (String subStr : split) {
			result = Math.max(longestSubstring(subStr, k), result);
		}

		return result;
	}
}