#include <iostream>
#include <vector>
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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums, int start, int end) {
		if (start == end) {
			return nullptr;
		}
		int maxI = start, maxV = 0;
		for (int i = start; i < end; i++) {
			if (maxV < nums[i]) {
				maxV = nums[i];
				maxI = i;
			}
		}
		TreeNode *left = constructMaximumBinaryTree(nums, start, maxI);
		TreeNode *right = constructMaximumBinaryTree(nums, maxI + 1, end);
		TreeNode *ans = new TreeNode(maxV, left, right);
		return ans;
	}
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return constructMaximumBinaryTree(nums, 0, nums.size());
    }
};

int main(void){
	Solution solution = Solution();
	cout << solution.constructMaximumBinaryTree(vector<int> {3, 2, 1, 6, 0, 5}) << endl;
}
