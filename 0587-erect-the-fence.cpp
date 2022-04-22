#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int cross(const vector<int> &p, const vector<int> &q, const vector<int> &r) {
		return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0]);
	}

	int distance(const vector<int> &p, const vector<int> &q) {
		return (p[0] - q[0]) * (p[0] - q[0]) + (p[1] - q[1]) * (p[1] - q[1]);
	}

	vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
		int n = trees.size();
		if (n < 4) {
			return trees;
		}

		int bottom = 0;
		for (int i = 0; i < n; i++) {
			if (trees[i][1] < trees[bottom][1]) {
				bottom = i;
			}
		}
		swap(trees[bottom], trees[0]);

		sort(trees.begin() + 1, trees.end(), [&](const vector<int> &a, const vector<int> &b){
			int diff = cross(trees[0], a, b) - cross(trees[0], b, a);
			if (diff == 0) {
				return distance(trees[0], a) < distance(trees[0], b);
			}
			else {
				return diff > 0;
			}
		});

		int r = n - 1;
		while (r >= 0 && cross(trees[0], trees[n - 1], trees[r]) == 0) {
			--r;
		}
		for (int l = r + 1, h = n - 1; l < h; l++, h--) {
			swap(trees[l], trees[h]);
		}
		stack<int> st;
		st.emplace(0);
		st.emplace(1);
		for (int i = 2; i < n; i++) {
			int top = st.top();
			st.pop();
			while (!st.empty() && cross(trees[st.top()], trees[top], trees[i]) < 0) {
				top = st.top();
				st.pop();
			}
			st.emplace(top);
			st.emplace(i);
		}

		vector<vector<int>> ans;
		while (!st.empty()) {
			ans.emplace_back(trees[st.top()]);
			st.pop();
		}
		return ans;
	}
};

void printVector(const vector<vector<int>> &v){
	for (auto &e : v) {
		for (auto &i : e)
			cout << i << ", ";
		cout << endl;
	}
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.outerTrees(vector<vector<int>>{ { 1, 1 }, { 2, 2 }, { 2, 0 }, { 2, 4 }, { 3, 3 }, { 4, 2 } }));
}
