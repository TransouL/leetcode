#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> missingTwo(vector<int>& nums) {
		int n = nums.size() + 2;
		int s = (1 + n) * n / 2;
		long long squres = 0;
		for (int i = 1; i <=n; i++) {
			squres += (long long) i * i;
		}
		for (auto &num : nums) {
			s -= num;
			squres -= num * num;
		}
		int delta = sqrt(squres * 2 - s * s);
		return { (s - delta) / 2, (s + delta) / 2 };
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.missingTwo(vector<int> {1}));
	printVector(solution.missingTwo(vector<int> {2, 3}));
}
