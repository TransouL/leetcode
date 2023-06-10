#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
	int f(string str) {
		char mnc = 'z';
		int cnt = 0;
		for (auto c : str){
			if (c < mnc) {
				mnc = c;
				cnt = 1;
			}
			else if (c == mnc) {
				++cnt;
			}
		}
		return cnt;
	}

public:
	vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
		int n = queries.size();
		vector<int> fq(n);
		map<int, int> fw;
		for (int i = 0; i < n; i++) {
			fq[i] = f(queries[i]);
		}
		for (int i = 0; i < words.size(); i++) {
			++fw[f(words[i])];
		}

		int m = fw.size(), currIdx = m - 1, currCnt = 0;
		vector<int> fwPreValue(m + 1, 0), fwPreCnt(m + 1, 0);
		for (auto it = fw.rbegin(); it != fw.rend(); ++it) {
			int v = it->first, c = it->second;
			currCnt += c;
			fwPreValue[currIdx + 1] = v;
			fwPreCnt[currIdx] = currCnt;
			--currIdx;
		}

		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			int pos = lower_bound(fwPreValue.begin(), fwPreValue.end(), fq[i]) - fwPreValue.begin();
			if (pos == m + 1 || fwPreValue[pos] > fq[i]){
				--pos;
			}
			ans[i] = fwPreCnt[pos];
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &&e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.numSmallerByFrequency(vector<string>{"cbd"}, vector<string>{"zaaaz"}));
	printVector(solution.numSmallerByFrequency(vector<string>{"bbb", "cc"}, vector<string>{"a", "aa", "aaa", "aaaa"}));
	printVector(solution.numSmallerByFrequency(vector<string>{"aabbabbb", "abbbabaa", "aabbbabaa", "aabba", "abb", "a", "ba", "aa", "ba", "baabbbaaaa", "babaa", "bbbbabaa"}, vector<string>{"b", "aaaba", "aaaabba", "aa", "aabaabab", "aabbaaabbb", "ababb", "bbb", "aabbbabb", "aab", "bbaaababba", "baaaaa"}));
}