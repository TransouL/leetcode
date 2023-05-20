#include <iostream>
#include <algorithm>
#include <tuple>
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
	int ans = 0;

	tuple<int, int, int> dfs(TreeNode *node) {
		if (node == nullptr)
			return make_tuple(INT_MAX, INT_MIN, 0);

		tuple<int, int, int> tl = dfs(node->left), tr = dfs(node->right);
		int l_min = get<0>(tl), l_max = get<1>(tl), l_sum = get<2>(tl), r_min = get<0>(tr), r_max = get<1>(tr), r_sum = get<2>(tr);
		int x = node->val;
		if (x <= l_max || x >= r_min)
			return make_tuple(INT_MIN, INT_MAX, 0);

		int s = l_sum + r_sum + x;
		ans = max(ans, s);

		return make_tuple (min(l_min, x), max(r_max, x), s);
	}

public:
	int maxSumBST(TreeNode* root) {
		dfs(root);
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	TreeNode node1 = TreeNode(1);
	TreeNode node2 = TreeNode(2);
	TreeNode node3 = TreeNode(3, &node1, &node2);
	TreeNode node4 = TreeNode(4, &node3, nullptr);
	cout << solution.maxSumBST(&node4) << endl;
}
