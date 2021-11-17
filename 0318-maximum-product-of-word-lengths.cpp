#include <iostream>
#include <vector>

using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))

int wordsMask[1000] = { 0 };

class Solution {
public:
	int maxProduct(vector<string>& words) {
		for (size_t i = 0; i < words.size(); i++){
			int mask = 0;
			for (auto &ch : words[i]){
				mask |= (1 << (ch - 'a'));
			}
			wordsMask[i] = mask;
		}
		unsigned int ans = 0;
		for (size_t i = 0; i < words.size(); i++){
			for (size_t j = i + 1; j < words.size(); j++){
				if ((wordsMask[i] & wordsMask[j]) == 0){
					ans = max(ans, words[i].length() * words[j].length());
				}
			}
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.maxProduct(vector<string>{ "abcw", "baz", "foo", "bar", "xtfn", "abcdef"}) << endl;
	cout << solution.maxProduct(vector<string>{ "a", "ab", "abc", "d", "cd", "bcd", "abcd"}) << endl;
	cout << solution.maxProduct(vector<string>{ "a", "aa", "aaa", "aaaa"}) << endl;
}