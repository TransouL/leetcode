// import java.util.Arrays;

class Solution {
	public String largestNumber(int[] nums) {
		int n = nums.length;
		String[] numsStr = new String[n];
		for (int i = 0; i < n; i++) {
			numsStr[i] = String.valueOf(nums[i]);
		}

		Arrays.sort(numsStr, (a, b) -> {
			return (b + a).compareTo(a + b);
		});

		if (numsStr[0].equals("0")) {
			return "0";
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			sb.append(numsStr[i]);
		}
		return sb.toString();
	}

//	public static void main(String[] args) {
//		Solution solution = new Solution();
//		System.out.println(solution.largestNumber(new int[]{10, 2}));
//		System.out.println(solution.largestNumber(new int[]{3, 30, 34, 5, 9}));
//		System.out.println(solution.largestNumber(new int[]{1}));
//		System.out.println(solution.largestNumber(new int[]{10}));
//		System.out.println(solution.largestNumber(new int[]{0, 0}));
//	}
}