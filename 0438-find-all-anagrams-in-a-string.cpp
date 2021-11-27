#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		int cnts[26] = { 0 };
		size_t sLen = s.length(), pLen = p.length();
		if (sLen >= pLen) {
			for (auto ch : p)
				cnts[ch - 'a']++;

			for (size_t i = 0; i < pLen; i++) {
				cnts[s[i] - 'a']--;
			}
			if (check(cnts))
				ans.push_back(0);

			for (size_t i = pLen; i < sLen; i++) {
				cnts[s[i - pLen] - 'a']++;
				cnts[s[i] - 'a']--;
				if (check(cnts))
					ans.push_back(i - pLen + 1);
			}
		}
		return ans;
	}
private:
	bool check(int *cnts){
		for (size_t i = 0; i < 26; i++) {
			if (cnts[i] != 0)
				return false;
		}
		return true;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v)
		cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.findAnagrams("cbaebabacd", "abc"));
	printVector(solution.findAnagrams("abab", "ab"));
	printVector(solution.findAnagrams("aaaaaaaaaa", "aaaaaaaaaaaaa"));
}