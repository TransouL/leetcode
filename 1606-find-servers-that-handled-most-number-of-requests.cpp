#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
	vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
		priority_queue<int, vector<int>, greater<int>> available;
		for (size_t i = 0; i < k; i++) {
			available.push(i);
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> busy;
		vector<int> requests(k);
		for (int i = 0; i < arrival.size(); i++) {
			int a = arrival[i], l = load[i];
			while (!busy.empty() && busy.top().first <= a) {
				int id = busy.top().second;
				available.push(i + ((id - i) % k + k) % k);
				busy.pop();
			}
			if (!available.empty()){
				int id = available.top() % k;
				available.pop();
				++requests[id];
				busy.emplace(make_pair(a + l, id));
			}
		}

		int max_ = *max_element(requests.begin(), requests.end());
		vector<int> ans;
		for (size_t i = 0; i < k; i++) {
			if (max_ == requests[i]) {
				ans.emplace_back(i);
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
	printVector(solution.busiestServers(3, vector<int>{ 1, 2, 3, 4, 5 }, vector<int>{ 5, 2, 3, 3, 3 }));
	printVector(solution.busiestServers(3, vector<int>{ 1, 2, 3, 4 }, vector<int>{ 1, 2, 1, 2 }));
	printVector(solution.busiestServers(3, vector<int>{ 1, 2, 3 }, vector<int>{ 10, 12, 11 }));
	printVector(solution.busiestServers(3, vector<int>{ 1, 2, 3, 4, 8, 9, 10 }, vector<int>{ 5, 2, 10, 3, 1, 2, 2 }));
	printVector(solution.busiestServers(1, vector<int>{ 1 }, vector<int>{ 1 }));
}
