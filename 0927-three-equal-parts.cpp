#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
	vector<int> threeEqualParts(vector<int>& arr) {
		int sum = accumulate(arr.begin(), arr.end(), 0);
		if (sum % 3 != 0) {
			return { -1, -1 };
		}
		if (sum == 0) {
			return { 0, 2 };
		}

		int partial = sum / 3;
		int first = 0, second = 0, third = 0, cur = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == 1) {
				if (cur == 0) {
					first = i;
				}
				else if (cur == partial) {
					second = i;
				}
				else if (cur == partial * 2) {
					third = i;
				}
				++cur;
			}
		}

		int len = arr.size() - third;
		if (first + len <= second && second + len <= third) {
			for (int i = 0; i < len; i++) {
				if (arr[first + i] != arr[second + i] || arr[first + i] != arr[third + i]) {
					return { -1, -1 };
				}
			}
			return{ first + len - 1, second + len };
		}
		return{ -1, -1 };
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.threeEqualParts(vector<int> {1, 0, 1, 0, 1}));
	printVector(solution.threeEqualParts(vector<int> {1, 1, 0, 1, 1}));
	printVector(solution.threeEqualParts(vector<int> {1, 1, 0, 0, 1}));
}
