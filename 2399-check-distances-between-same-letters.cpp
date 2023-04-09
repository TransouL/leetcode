#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool checkDistances(string s, vector<int>& distance) {
		bool visited[26] = { false };
		for (int i = 0; i < s.size(); i++) {
			int idx = s[i] - 'a';
			if (visited[idx]) {
				if (distance[idx] != i) {
					return false;
				}
			}
			else {
				distance[idx] += i + 1;
				visited[idx] = true;
			}
		}
		return true;
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.checkDistances("abaccb", vector<int>{1, 3, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}) << endl;
	cout << solution.checkDistances("aa", vector<int>{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}) << endl;
}