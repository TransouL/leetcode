#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
	vector<double> sampleStats(vector<int>& count) {
		bool foundMN = false;
		double mn, mx, mean, median = 0.0, mode;
		int tot = accumulate(count.begin(), count.end(), 0);
		int currCnt = 0, modeCnt = 0;
		int left = (tot + 1) / 2, right = tot / 2 + 1;
		long long sum = 0;
		for (int i = 0; i < 256; i++) {
			if (count[i] == 0) {
				continue;
			}
			if (!foundMN) {
				mn = i;
				foundMN = true;
			}
			mx = i;
			sum += (long long)count[i] * i;
			if (count[i] > modeCnt) {
				modeCnt = count[i];
				mode = i;
			}
			if (currCnt < left && currCnt + count[i] >= left) {
				median += i;
			}
			if (currCnt < right && currCnt + count[i] >= right) {
				median += i;
			}
			currCnt += count[i];
		}
		mean = (double)sum / tot;
		median /= 2.0;
		return{ mn, mx, mean, median, mode };
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &&e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.sampleStats(vector<int>{0, 1, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}));
}