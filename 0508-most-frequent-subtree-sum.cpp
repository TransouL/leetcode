#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	unordered_map<int, int> stats;
	int getSum(TreeNode* root) {
		if (root == nullptr)
			return 0;
		int res = root->val + getSum(root->left) + getSum(root->right);
		stats[res]++;
		return res;
	}
public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
		getSum(root);
		vector<int> ans;
		int maxF = 0;
		for (auto p : stats) {
			int sum = p.first, freq = p.second;
			if (maxF < freq) {
				maxF = freq;
				ans.clear();
				ans.push_back(sum);
			}
			else if (maxF == freq) {
				ans.push_back(sum);
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
	TreeNode node2 = TreeNode(2);
	TreeNode nodem3 = TreeNode(-3);
	TreeNode node5 = TreeNode(5, &node2, &nodem3);
	printVector(solution.findFrequentTreeSum(&node5));
}
