#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n);
		int left = 0, right = n - 1;
		for (auto &num : nums) {
			if (num & 1)
				ans[right--] = num;
			else
				ans[left++] = num;
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
	printVector(solution.sortArrayByParity(vector<int> {3, 1, 2, 4}));
}
