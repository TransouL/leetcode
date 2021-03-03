public class Solution {
	public int maxEnvelopes(int[][] envelopes) {
		if (envelopes.length == 0) {
			return 0;
		}

		Arrays.sort(envelopes, (e1, e2) -> {
			if (e1[0] != e2[0])
				return e1[0] - e2[0];
			else
				return e2[1] - e1[1];
		});

		List<Integer> f = new ArrayList<Integer>();
		f.add(envelopes[0][1]);
		for (int i = 1; i < envelopes.length; ++i) {
			int num = envelopes[i][1];
			if (num > f.get(f.size() - 1)) {
				f.add(num);
			} else {
				int index = binarySearch(f, num);
				f.set(index, num);
			}
		}
		return f.size();
	}

	public int binarySearch(List<Integer> f, int target) {
		int low = 0, high = f.size() - 1;
		while (low < high) {
			int mid = (high - low) / 2 + low;
			if (f.get(mid) < target) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}
		return low;
	}
}