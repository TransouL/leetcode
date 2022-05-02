#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	vector<string> reorderLogFiles(vector<string>& logs) {
		vector<string> digs, ans;
		map<string, set<string>> lets;
		for (auto &log : logs) {
			int separator = log.find(' ');
			if (isdigit(log[separator + 1])) {
				digs.push_back(log);
			}
			else {
				string content = log.substr(separator + 1);
				auto it = lets.find(content);
				if (it != lets.end()) {
					it->second.insert(log);
				}
				else{
					set<string> st;
					st.insert(log);
					lets.emplace(log.substr(separator + 1), st);
				}
				
			}
		}
		for (auto &log : lets) {
			ans.insert(ans.end(), log.second.begin(), log.second.end());
		}
		ans.insert(ans.end(), digs.begin(), digs.end());
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
	printVector(solution.reorderLogFiles(vector<string> {"dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"}));
	printVector(solution.reorderLogFiles(vector<string> {"a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog", "a8 act zoo", "a2 act car"}));
}
