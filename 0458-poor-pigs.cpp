#include <iostream>

using namespace std;

class Solution {
public:
	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
		return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.poorPigs(1000, 15, 60) << endl;
	cout << solution.poorPigs(4, 15, 15) << endl;
	cout << solution.poorPigs(4, 15, 30) << endl;
}