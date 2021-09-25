class Solution {
	public int getSum(int a, int b) {
		# Python return int(math.log2(pow(2, a) * pow(2, b)))  # -1000, -1000 -> ValueError: math domain error
		while (b != 0) {
			int carry = (a & b) << 1;
			a = a ^ b;
			b = carry;
		}
		return a;
	}

	public static void main(String[] args) {
		Solution solution = new Solution();
		System.out.println(solution.getSum(1, 2));
		System.out.println(solution.getSum(2, 3));
		System.out.println(solution.getSum(1000, 1000));
		System.out.println(solution.getSum(-1000, -1000));
		System.out.println(solution.getSum(-1000, 1000));
	}
}