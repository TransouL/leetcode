#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> lexicalOrder(int n) {
		vector<int> ans(n);
		int curr = 1;
		for (int i = 0; i < n; i++) {
			ans[i] = curr;
			if (curr * 10 <= n) {
				curr *= 10;
			}
			else {
				while (curr % 10 == 9 || curr == n) {
					curr /= 10;
				}
				++curr;
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
	printVector(solution.lexicalOrder(13));
	printVector(solution.lexicalOrder(2));
	printVector(solution.lexicalOrder(1000));
	printVector(solution.lexicalOrder(190));
}
