public class Solution {
	public boolean isMonotonic(int[] A) {
		byte changed = 0; // 1 increased; -1 decreased
		int last = A[0];
		for (int i = 1; i < A.length; i++) {
			if (changed == 0) {
				if (A[i] > last)
					changed = 1;
				else if (A[i] < last)
					changed = -1;
			} else if (changed > 0) {
				if (A[i] < last)
					return false;
			} else {
				if (A[i] > last)
					return false;
			}
			last = A[i];
		}
		return true;
	}
}