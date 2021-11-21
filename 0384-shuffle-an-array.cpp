#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	Solution(vector<int>& nums) {
		this->orig.resize(nums.size());
		copy(nums.begin(), nums.end(), orig.begin());
		this->curr = nums;
	}

	vector<int> reset() {
		return orig;
	}

	vector<int> shuffle() {
		for (size_t i = 0; i < curr.size(); i++){
			int j = i + rand() % (curr.size() - i);
			swap(curr[i], curr[j]);
		}
		return curr;
	}

private:
	vector<int> curr;
	vector<int> orig;
};

int main(void){
	Solution solution = Solution(vector<int> {1, 3, 2});
	vector<int> resetNums = solution.reset();
	for (auto num : resetNums)
		cout << num << " ";
	cout << endl;
	vector<int> shuffleNums = solution.shuffle();
	for (auto num : shuffleNums)
		cout << num << " ";
	cout << endl;
}