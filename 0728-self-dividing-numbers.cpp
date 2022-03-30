#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> ans;
		for (int i = left; i <= right; i++) {
			int curr = i;
			bool isSelfDividing = true;
			while (curr) {
				int remain = curr % 10;
				if (remain == 0 || i % remain != 0) {
					isSelfDividing = false;
					break;
				}
				curr /= 10;
			}
			if (isSelfDividing) {
				ans.emplace_back(i);
			}
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.selfDividingNumbers(1, 22));
	printVector(solution.selfDividingNumbers(47, 85));
	printVector(solution.selfDividingNumbers(1, 10000));
}
