#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximumSwap(int num) {
		vector<int> orig;
		while (num) {
			orig.emplace_back(num % 10);
			num /= 10;
		}
		vector<int> sorted = orig;
		sort(sorted.begin(), sorted.end());
		int n = orig.size();
		for (int i = n - 1; i >= 0; --i) {
			if (orig[i] != sorted[i]) {
				for (int j = 0; j < i; j++) {
					if (orig[j] == sorted[i]) {
						swap(orig[j], orig[i]);
						break;
					}
				}
				break;
			}
		}
		int ans = 0;
		for (int i = n - 1; i >= 0; --i) {
			ans = ans * 10 + orig[i];
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.maximumSwap(2736) << endl;
	cout << solution.maximumSwap(9973) << endl;
}
