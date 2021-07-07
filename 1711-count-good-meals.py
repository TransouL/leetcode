from typing import List
from collections import Counter


class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        counter = Counter(deliciousness)
        keys = list(counter.keys())
        n = len(keys)
        ans = 0

        def is2power(k: int) -> bool:
            if k <= 0:
                return False
            return k & (k - 1) == 0

        def combination(k: int) -> int:
            return k * (k - 1) // 2

        for i in range(n):
            if counter[keys[i]] > 1 and is2power(keys[i] * 2):
                ans += combination(counter[keys[i]])
            for j in range(i + 1, n):
                if is2power(keys[i] + keys[j]):
                    ans += counter[keys[i]] * counter[keys[j]]

        return ans % 1000000007


solution = Solution()
print(solution.countPairs([1, 3, 5, 7, 9]))
print(solution.countPairs([1, 1, 1, 3, 3, 3, 7]))
print(solution.countPairs(
    [2160, 1936, 3, 29, 27, 5, 2503, 1593, 2, 0, 16, 0, 3860, 28908, 6, 2, 15, 49, 6246, 1946, 23, 105, 7996, 196, 0, 2,
     55, 457, 5, 3, 924, 7268, 16, 48, 4, 0, 12, 116, 2628, 1468]))



"""
Java:

import java.util.*;

class Solution {
	private int combination(long k) {
		return (int) (k * (k - 1) / 2 % 1000000007);
	}

	public int countPairs(int[] deliciousness) {
		int maxVal = 0;
		Map<Integer, Integer> counter = new HashMap<Integer, Integer>();
		for (int val : deliciousness) {
			maxVal = Math.max(maxVal, val);
			counter.put(val, counter.getOrDefault(val, 0) + 1);
		}
		int ans = 0;
		List<Integer> keys = new ArrayList<>(counter.keySet());
		Collections.sort(keys);

		for (int key : keys) {
			for (int target_sum = 1; target_sum <= maxVal * 2; target_sum <<= 1) {
				if (counter.get(key) > 1 && target_sum == key * 2) {
					ans = (ans + combination(counter.get(key))) % 1000000007;
				}
				if (target_sum - key > key && counter.containsKey(target_sum - key)) {
					ans = (ans + counter.get(key) * counter.get(target_sum - key)) % 1000000007;
				}
			}
		}
		return ans;
	}

	public static void main(String[] args) {
		Solution solution = new Solution();
		System.out.println(solution.countPairs(new int[]{1, 3, 5, 7, 9}));
		System.out.println(solution.countPairs(new int[]{1, 1, 1, 3, 3, 3, 7}));
		System.out.println(solution.countPairs(new int[]{2160, 1936, 3, 29, 27, 5, 2503, 1593, 2, 0, 16, 0, 3860, 28908, 6, 2, 15, 49, 6246, 1946, 23, 105, 7996, 196, 0, 2,
				55, 457, 5, 3, 924, 7268, 16, 48, 4, 0, 12, 116, 2628, 1468}));
	}
}
"""

