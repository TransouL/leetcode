#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> shortestToChar(string s, char c) {
		int n = s.length();
		vector<int> ans(n); // �������ʹ���㹻���ֵ�� ans(n, 10001) ��ʼ�����������ҵ�target�ַ��ĵط���ans[filled] = min(ans[filled], i);
		int filled = 0, curr = 0;
		bool leftExist = false;
		// һ�α���
		for (auto &ch : s) {
			if (ch == c) {
				// �ҵ�target�ַ��󣬴�filled��ʼ���±Ƚ�(����������target�ַ��ľ���)
				for (int i = curr; i >= 0 ; --i) {
					ans[filled] = leftExist ? min(ans[filled], i) : i;
					++filled;
				}
				curr = 0;
				leftExist = true;
			}
			else {
				// ��ȷ��������ʱ��ÿ�ο�����ֱ�Ӹ��·�target�ַ��ľ��� (��������в��ı�filled���)
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
