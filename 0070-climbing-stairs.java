public class Solution {
	public static int climbStairs(int n) {
		if(n == 0) {
			return 0;
		} else if (n == 1) {
			return 1;
		} else if (n == 2) {
			return 2;
		} 
		int fn_2 = 1;
		int fn_1 = 2;
		int fn = 3;
		for (int i = 3; i <= n; i++) {
			fn = fn_2 + fn_1;
			fn_2 = fn_1;
			fn_1 = fn;
		}
		return fn;
    }
}