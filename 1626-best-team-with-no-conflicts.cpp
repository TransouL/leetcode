#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        int n = scores.size();
        pair<int, int> a[n]; // 旧版本C++，可以写1000
        for (int i = 0; i < n; ++i)
            a[i] = {scores[i], ages[i]};
        sort(a, a + n);

		int f[n]; memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j)
                if (a[j].second <= a[i].second)
                    f[i] = max(f[i], f[j]);
            f[i] += a[i].first;
        }
        return *max_element(f, f + n);
    }
};

int main(void) {
	Solution solution = Solution();
	cout << solution.bestTeamScore(vector<int>{1, 3, 5, 10, 15}, vector<int>{1, 2, 3, 4, 5}) << endl;
	cout << solution.bestTeamScore(vector<int>{4, 5, 6, 5}, vector<int>{2, 1, 2, 1}) << endl;
	cout << solution.bestTeamScore(vector<int>{1, 2, 3, 5}, vector<int>{8, 9, 10, 1}) << endl;
}