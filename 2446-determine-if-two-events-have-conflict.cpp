#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool haveConflict(vector<string>& e1, vector<string>& e2) {
		return e1[1] >= e2[0] && e2[1] >= e1[0];
	}
};

int main(void) {
	Solution solution = Solution();
	cout << solution.haveConflict(vector<string>{"01:15", "02:00"}, vector<string>{"02:00", "03:00"}) << endl;
	cout << solution.haveConflict(vector<string>{"01:00", "02:00"}, vector<string>{"01:20", "03:00"}) << endl;
	cout << solution.haveConflict(vector<string>{"10:00", "11:00"}, vector<string>{"14:00", "15:00"}) << endl;
}