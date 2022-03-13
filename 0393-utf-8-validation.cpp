#include <iostream>
#include <vector>

using namespace std;

class Solution {
	static const int MASK1 = 1 << 7;
	static const int MASK2 = (1 << 7) + (1 << 6);

	bool isValid(int num) {
		return (num & MASK2) == MASK1;
	}

	int getBytes(int num) {
		if ((num & MASK1) == 0)
			return 1;
		int res = 0;
		int mask = MASK1;
		while ((num & mask) != 0) {
			if (res > 3) {
				return -1;
			}
			++res;
			mask >>= 1;
		}
		return res > 1 ? res : -1;
	}

public:
	bool validUtf8(vector<int>& data) {
		int n = data.size();
		int startIdx = 0;
		while (startIdx < n) {
			int firstChar = data[startIdx];
			int bytes = getBytes(firstChar);
			if (bytes < 0 || startIdx + bytes > n) {
				return false;
			}
			for (int i = 1; i < bytes; i++){
				if (!isValid(data[startIdx + i]))
					return false;
			}
			startIdx += bytes;
		}
		return true;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.validUtf8(vector<int> {197, 130, 1}) << endl;
	cout << solution.validUtf8(vector<int> {235, 140, 4}) << endl;
}
