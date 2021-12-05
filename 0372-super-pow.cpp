#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1337;

class Solution {
public:
	int superPow(int a, vector<int>& b) {
		int ans = 1;
		for (int i = b.size() - 1; i >= 0; --i){
			ans = (long)ans * quick_pow(a, b[i]) % MOD;
			a = quick_pow(a, 10);
		}
		return ans;
	}
private:
	int quick_pow(int x, int n) {
		int res = 1;
		while (n) {
			if (n & 1)
				res = (long)res * x % MOD;
			x = (long)x * x % MOD;
			n >>= 1;
		}
		return res;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.superPow(2, vector<int>{ 3 }) << endl;
	cout << solution.superPow(2, vector<int>{ 1, 0 }) << endl;
	cout << solution.superPow(1, vector<int>{ 4, 3, 3, 8, 5, 2 }) << endl;
	cout << solution.superPow(2147483647, vector<int>{ 2, 0, 0 }) << endl;
}