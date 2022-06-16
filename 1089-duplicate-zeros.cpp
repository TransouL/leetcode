#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		int n = arr.size();
		if (n == 1) {
			return;
		}

		int zeroCnt = 0;
		int i = 0;
		for (; i + zeroCnt < n - 1; i++) {
			if (arr[i] == 0) {
				++zeroCnt;
			}
		}

		bool isLastCopyZero = i + zeroCnt == n;
		if (isLastCopyZero) {
			i = n - 1;
		}
		else {
			arr[n - 1] = arr[n - 1 - zeroCnt];
			i = n - 2;
		}
		for (; i >= 0; --i) {
			arr[i] = arr[i - zeroCnt];
			if (arr[i] == 0) {
				--zeroCnt;
				arr[i - 1] = 0;
				--i;
			}
		}
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	vector<int> arr = { 1, 0, 2, 3, 0, 4, 5, 0 };
	solution.duplicateZeros(arr);
	printVector(arr);
	arr = { 1, 2, 3 };
	solution.duplicateZeros(arr);
	printVector(arr);
	arr = { 0, 0, 0, 0, 0, 0, 0 };
	solution.duplicateZeros(arr);
	printVector(arr);
	arr = { 1, 5, 2, 0, 6, 8, 0, 6, 0 };
	solution.duplicateZeros(arr);
	printVector(arr);
}