#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> shortestToChar(string s, char c) {
		int n = s.length();
		vector<int> ans(n); // 这里如果使用足够大的值如 ans(n, 10001) 初始化，则下面找到target字符的地方：ans[filled] = min(ans[filled], i);
		int filled = 0, curr = 0;
		bool leftExist = false;
		// 一次遍历
		for (auto &ch : s) {
			if (ch == c) {
				// 找到target字符后，从filled开始重新比较(和左右两个target字符的距离)
				for (int i = curr; i >= 0 ; --i) {
					ans[filled] = leftExist ? min(ans[filled], i) : i;
					++filled;
				}
				curr = 0;
				leftExist = true;
			}
			else {
				// 当确定左侧存在时，每次可以先直接更新非target字符的距离 (这个过程中不改变filled标记)
				if (leftExist) {
					ans[filled + curr] = curr + 1;
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
	printVector(solution.shortestToChar("loveleetcode", 'e'));
	printVector(solution.shortestToChar("aaab", 'b'));
}
