#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

class Solution {
public:
	vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
		int n = names.size();
		vector<pii> order(n);
		for (int i = 0; i < n; i++) {
			order[i] = make_pair(heights[i], i);
		}
		sort(order.begin(), order.end());
		vector<string> ans(n);
		for (int i = 0; i < n; i++) {
			ans[n - i - 1] = names[order[i].second];
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &&e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.sortPeople(vector<string>{"Mary", "John", "Emma"}, vector<int>{180, 165, 170}));
	printVector(solution.sortPeople(vector<string>{"Alice", "Bob", "Bob"}, vector<int>{155, 185, 150}));
}