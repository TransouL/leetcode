#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int countHighestScoreNodes(vector<int>& parents) {
		int n = parents.size();
		vector<int> leftSons(n, -1);
		vector<int> rightSons(n, -1);
		vector<int> count(n, 1);
		vector<bool> flag(n, false);
		for (int s = 1; s < n; ++s) {
			int p = parents[s];
			if (leftSons[p] == -1) {
				leftSons[p] = s;
			}
			else {
				rightSons[p] = s;
			}
		}

		queue<int> finished;
		for (int i = 0; i < n; i++) {
			if (leftSons[i] == -1) {
				finished.emplace(i);
			}
		}

		while (!finished.empty()) {
			int node = finished.front();
			finished.pop();
			int p = parents[node];
			count[p] += count[node];
			flag[node] = true;

			if (p != 0 && (rightSons[p] == -1 || (leftSons[p] == node && flag[rightSons[p]]) || (rightSons[p] == node && flag[leftSons[p]]))) {
				finished.emplace(p);
			}
		}

		long max;
		int maxCount = 1;
		if (rightSons[0] == -1) {
			max = count[leftSons[0]];
		}
		else {
			max = (long)count[leftSons[0]] * count[rightSons[0]];
		}
		for (int i = 1; i < n; i++) {
			int left = leftSons[i], right = rightSons[i];
			long curr;
			if (left == -1) {
				curr = n - 1;
			}
			else if (right == -1) {
				curr = (long)count[left] * (n - count[left] - 1);
			}
			else {
				curr = (long)count[left] * count[right] * (n - count[left] - count[right] - 1);
			}

			if (curr > max) {
				max = curr;
				maxCount = 1;
			}
			else if (curr == max) {
				++maxCount;
			}
		}

		return maxCount;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.countHighestScoreNodes(vector<int> {-1, 2, 0, 2, 0}) << endl;
	cout << solution.countHighestScoreNodes(vector<int> {-1, 2, 0}) << endl;
	cout << solution.countHighestScoreNodes(vector<int> {-1, 11, 28, 44, 42, 30, 28, 24, 37, 10, 4, 8, 8, 37, 29, 7, 43, 43, 6, 46, 15, 45, 14, 32, 14, 0, 7, 3, 4, 44, 0, 22, 5, 46, 1, 38, 16, 24, 25, 35, 17, 23, 30, 15, 25, 10, 34, 26}) << endl; // 1
	cout << solution.countHighestScoreNodes(vector<int> {-1, 3, 3, 5, 7, 6, 0, 0}) << endl; // 2
}
