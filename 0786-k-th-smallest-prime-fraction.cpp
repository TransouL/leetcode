#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
		size_t n = arr.size();
		auto cmp = [&](const pair<int, int> &x, const pair<int, int> &y) {
			return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
		};

		priority_queue <pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
		for (size_t j = 1; j < n; j++){
			q.emplace(0, j);
		}

		for (size_t _ = 1; _ < k; _++){
			pair<int, int> pair = q.top();
			int i = pair.first, j = pair.second;
			q.pop();
			if (i + 1 < j)
				q.emplace(i + 1, j);
		}

		return{ arr[q.top().first], arr[q.top().second] };
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.kthSmallestPrimeFraction(vector<int> {1, 2, 3, 5}, 3));
	printVector(solution.kthSmallestPrimeFraction(vector<int> {1, 7}, 1));
}