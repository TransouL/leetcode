#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		unordered_map<string, int> stats;
		for (auto &item : cpdomains) {
			int n = item.size(), cnt = 0;
			for (int i = 0; i < n; i++) {
				auto ch = item[i];
				if (isdigit(ch)) {
					cnt = cnt * 10 + (ch - '0');
				}
				else {
					break;
				}
			}
			string domain = "";
			for (int i = n - 1; i >= 0; --i) {
				auto ch = item[i];
				if (ch == ' ') {
					stats[domain] += cnt;
					break;
				}
				else if (ch == '.') {
					stats[domain] += cnt;
					domain = ch + domain;
				}
				else {
					domain = ch + domain;
				}
			}
		}
		vector<string> ans;
		for (auto it = stats.begin(); it != stats.end(); ++it) {
			ans.emplace_back(to_string(it->second) + ' ' + it->first);
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
	printVector(solution.subdomainVisits(vector<string> {"9001 discuss.leetcode.com"}));
	printVector(solution.subdomainVisits(vector<string> {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"}));
}
