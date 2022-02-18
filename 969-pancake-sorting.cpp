#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> pancakeSort(vector<int>& arr) {
		vector<int> ans;
		for (int i = arr.size(); i > 1; --i) {
			if (arr[i - 1] == i) {
				continue;
			}
			int index = max_element(arr.begin(), arr.begin() + i - 1) - arr.begin();
			if (index != 0) {
				reverse(arr.begin(), arr.begin() + index + 1);
				ans.emplace_back(index + 1);
			}
			reverse(arr.begin(), arr.begin() + i);
			ans.emplace_back(i);
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
	printVector(solution.pancakeSort(vector<int> {3, 2, 4, 1}));
	printVector(solution.pancakeSort(vector<int> {1, 2, 3}));
}
