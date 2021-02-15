class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] counts = new int[26];
		for (char c : tasks) {
			counts[c - 'A']++;
		}

		int maxCount = 0;
		int maxCountTypes = 0;
		for (int count : counts) {
			if (count > maxCount) {
				maxCount = count;
				maxCountTypes = 1;
			} else if (count == maxCount) {
				++maxCountTypes;
			}
		}

		if ((n + 1) * (maxCount - 1) + maxCountTypes > tasks.length) {
			return (n + 1) * (maxCount - 1) + maxCountTypes;
		} else {
			return tasks.length;
		}
    }
}