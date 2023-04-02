#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> prevPermOpt1(vector<int>& arr) {
		int n = arr.size();
		for (int i = n - 2; i >= 0 ; --i) {
			if (arr[i] > arr[i + 1]) {
				int targetIdx = (lower_bound(arr.begin() + i + 1, arr.end(), arr[i] - 1) - arr.begin());
				while (targetIdx == n || arr[targetIdx] >= arr[i] || (targetIdx > i + 1 && arr[targetIdx - 1] == arr[targetIdx])) {
					--targetIdx;
				}
				int tmp = arr[i];
				arr[i] = arr[targetIdx];
				arr[targetIdx] = tmp;
				break;

			}
		}
		return arr;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &&e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.prevPermOpt1(vector<int>{3, 2, 1}));
	printVector(solution.prevPermOpt1(vector<int>{1, 1, 5}));
	printVector(solution.prevPermOpt1(vector<int>{1, 9, 4, 6, 7}));
	printVector(solution.prevPermOpt1(vector<int>{3, 1, 1, 3}));
	printVector(solution.prevPermOpt1(vector<int>{6, 4, 5, 7}));
}