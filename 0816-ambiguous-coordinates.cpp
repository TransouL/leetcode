#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
	vector<string> getPos(string s) {
		vector<string> pos;
		if (s[0] != '0' || s == "0") {
			pos.push_back(s);
		}
		for (int p = 1; p < s.size(); p++) {
			if ((p != 1 && s[0] == '0') || s.back() == '0') {
				continue;
			}
			pos.push_back(s.substr(0, p) + "." + s.substr(p));
		}
		return pos;
	}
public:
	vector<string> ambiguousCoordinates(string s) {
		int n = s.size() - 2;
		vector<string> ans;
		s = s.substr(1, s.size() - 2);
		for (int l = 1; l < n; l++) {
			vector<string> lt = getPos(s.substr(0, l));
			if (lt.empty()) {
				continue;
			}
			vector<string> rt = getPos(s.substr(l));
			if (rt.empty()) {
				continue;
			}
			for (auto &i : lt) {
				for (auto &j : rt) {
					ans.push_back("(" + i + ", " + j + ")");
				}
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

int main(void) {
	Solution solution = Solution();
	printVector(solution.ambiguousCoordinates("(123)"));
	printVector(solution.ambiguousCoordinates("(00011)"));
	printVector(solution.ambiguousCoordinates("(0123)"));
	printVector(solution.ambiguousCoordinates("(100)"));
}
