#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
	int eatenApples(vector<int>& apples, vector<int>& days) {
		int n = apples.size(), ans = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
		for (int day = 0; day < n || !q.empty(); ++day) {
			if (day < n && apples[day] != 0) {
				q.emplace(make_pair(day + days[day] - 1, apples[day] <= days[day] ? apples[day] : days[day]));
			}

			while (!q.empty()) {
				pair<int, int> top = q.top();
				q.pop();
				if (top.first >= day) {
					++ans;
					if (top.second > 1) {
						q.emplace(make_pair(top.first, top.second - 1));
					}
					break;
				}
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.eatenApples(vector<int> { 1, 2, 3, 5, 2 }, vector<int> {3, 2, 1, 4, 2}) << endl;
	cout << solution.eatenApples(vector<int> {3, 0, 0, 0, 0, 2 }, vector<int> {3, 0, 0, 0, 0, 2}) << endl;
	cout << solution.eatenApples(vector<int> {2, 1, 10 }, vector<int> {2, 10, 1}) << endl;
}
