#include <iostream>
#include <vector>

#define min(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

class Solution {
public:
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int ans = duration, last = timeSeries[0];
		for (const int &time : timeSeries){
			ans += min(duration, (time - last));
			last = time;
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.findPoisonedDuration(vector<int>{1, 4}, 2) << endl;
	cout << solution.findPoisonedDuration(vector<int>{1, 2}, 2) << endl;
}
