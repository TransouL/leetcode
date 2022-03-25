#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
	int calPoints(vector<string>& ops) {
		vector<int> score;
		for (auto &op : ops) {
			switch (op[0]) {
			case 'C':
				score.pop_back();
				break;
			case 'D':
				score.push_back(score.back() * 2);
				break;
			case '+':
				score.push_back(score.back() + score.at(score.size() - 2));
				break;
			default:
				score.push_back(stoi(op));
				break;
			}
		}
		return accumulate(score.begin(), score.end(), 0);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.calPoints(vector<string> {"5", "2", "C", "D", "+"}) << endl;
	cout << solution.calPoints(vector<string> {"5", "-2", "4", "C", "D", "9", "+", "+"}) << endl;
	cout << solution.calPoints(vector<string> {"1"}) << endl;
}
