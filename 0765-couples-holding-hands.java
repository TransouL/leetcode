class Solution {
	public static int minSwapsCouples(int[] row) {
		int result = 0;

		int[] invertedIndex = new int[row.length];
		for (int i = 0; i < row.length; i++) {
			invertedIndex[row[i]] = i;
		}

		for (int i = 0; i < row.length; i += 2) {
			int pair;
			if (row[i] % 2 == 0) {
				pair = row[i] + 1;
			} else {
				pair = row[i] - 1;
			}
			if (row[i + 1] != pair) {
				int currentNext = row[i + 1];
				int pairIndex = invertedIndex[pair];
				row[pairIndex] = currentNext;
				invertedIndex[currentNext] = pairIndex;
				result++;
			}
		}

		return result;
	}
}