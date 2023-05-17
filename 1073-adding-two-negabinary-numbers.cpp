#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
		int i = arr1.size() - 1, j = arr2.size() - 1, carry = 0;
		vector<int> ans;
		while (i >= 0 || j >= 0 || carry) {
			int x = carry;
			if (i >= 0) {
				x += arr1[i];
			}
			if (j >= 0) {
				x += arr2[j];
			}

			if (x >= 2) {
				ans.push_back(x - 2);
				carry = -1;
			}
			else if (x >= 0) {
				ans.push_back(x);
				carry = 0;
			}
			else {
				ans.push_back(1);
				carry = 1;
			}
			--i;
			--j;
		}
		while (ans.size() > 1 && ans.back() == 0) {
			ans.pop_back();
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &&e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.addNegabinary(vector<int>{1, 1, 1, 1, 1}, vector<int>{1, 0, 1}));
	printVector(solution.addNegabinary(vector<int>{0}, vector<int>{0}));
	printVector(solution.addNegabinary(vector<int>{0}, vector<int>{1}));
}