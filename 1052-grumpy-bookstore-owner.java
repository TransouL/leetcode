public class Solution {
	public int maxSatisfied(int[] customers, int[] grumpy, int X) {
		int original = 0;
		for (int i = 0; i < customers.length; i++) {
			original += customers[i] * (grumpy[i] ^ 1);
		}
		int increase = 0;
		for (int i = 0; i < X; i++) {
			increase += customers[i] * grumpy[i];
		}
		int maxIncrease = increase;
		for (int i = X; i < customers.length; i++) {
			increase = increase - customers[i - X] * grumpy[i - X] + customers[i] * grumpy[i];
			maxIncrease = Math.max(maxIncrease, increase);
		}
		return original + maxIncrease;
	}
}