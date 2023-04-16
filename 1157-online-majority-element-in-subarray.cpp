#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>
using namespace std;

class MajorityChecker {
	static const int k = 20;
	const vector<int> arr;
	unordered_map<int, vector<int>> loc;
	mt19937 gen{ random_device{}()};

public:
	MajorityChecker(vector<int>& arr) :arr(arr) {
		for (int i = 0; i < arr.size(); i++) {
			loc[arr[i]].push_back(i);
		}
	}

	int query(int left, int right, int threshold) {
		int length = right - left + 1;
		uniform_int_distribution<int> dis(left, right);

		for (int i = 0; i < k; i++) {
			int x = arr[dis(gen)];
			vector<int> &pos = loc[x];
			int occ = upper_bound(pos.begin(), pos.end(), right) - lower_bound(pos.begin(), pos.end(), left);
			if (occ >= threshold) {
				return x;
			}
			else if (occ * 2 >= length) {
				return -1;
			}
		}

		return -1;
	}
};

int main(void){
	MajorityChecker majorityChecker = MajorityChecker(vector<int>{1, 1, 2, 2, 1, 1});
	cout << majorityChecker.query(0, 5, 4) << endl; // 1
	cout << majorityChecker.query(0, 3, 3) << endl; // -1
	cout << majorityChecker.query(2, 3, 2) << endl; // 2
}
