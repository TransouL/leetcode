#include <iostream>
using namespace std;
const int MOD = 1000000007;

class Solution {
	bool isPrime(int x) {
		if (x == 1)
			return false;
		if (x == 2 || x == 3)
			return true;
		if (x % 6 != 1 && x % 6 != 5)
			return false;
		for (int i = 5; i <= sqrt(x); i+= 6) {
			if (x % i == 0 || x % (i + 2) == 0)
				return false;
		}
		return true;
	}

public:
	int numPrimeArrangements(int n) {
		int primeCnt = 0, otherCnt = 0;
		for (int i = 1; i <=n; i++){
			if (isPrime(i)) {
				++primeCnt;
			}
			else {
				++otherCnt;
			}
		}
		long long ans = 1;
		for (int i = 2; i <= primeCnt; i++) {
			ans = ans * i % MOD;
		}
		for (int i = 2; i <= otherCnt; i++) {
			ans = ans * i % MOD;
		}
		return (int)ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.numPrimeArrangements(5) << endl;
	cout << solution.numPrimeArrangements(2) << endl;
	cout << solution.numPrimeArrangements(100) << endl;
}