#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> getFolderNames(vector<string>& names) {
		unordered_map<string, int> stats;
		vector<string> ans;
		for (auto &name : names) {
			if (stats.count(name)) {
				int currCnt = stats[name];
				for (int i = currCnt + 1; i < 50001; i++) {
					string suffixName = name + "(" + to_string(i) + ")";
					if (!stats.count(suffixName)) {
						ans.push_back(suffixName);
						stats[name] = i;
						break;
					}
				}
			}
			else {
				int m = name.size();
				if (m > 2 && name[m - 1] == ')' && isdigit(name[m - 2])) {
					int i = m - 3;
					for (; i >= 0 ; --i) {
						if (!isdigit(name[i])) {
							break;
						}
					}
					if (i > 0 && name[i] == '(') {
						string trimName = name.substr(0, i);
						if (stats.count(trimName) && (stats[trimName] >= stoi(name.substr(i + 1, m - i - 2)))) {
							for (int i = 1; i < 50001; i++) {
								string suffixName = name + "(" + to_string(i) + ")";
								if (!stats.count(suffixName)) {
									ans.push_back(suffixName);
									stats[name] = i;
									break;
								}
							}
						}
						else {
							ans.push_back(name);
							stats[name] = 0;
						}
					}
				}
				else {
					ans.push_back(name);
					stats[name] = 0;
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
	printVector(solution.getFolderNames(vector<string>{"pes", "fifa", "gta", "pes(2019)"}));
	printVector(solution.getFolderNames(vector<string>{"gta", "gta(1)", "gta", "avalon"}));
	printVector(solution.getFolderNames(vector<string>{"onepiece", "onepiece(1)", "onepiece(2)", "onepiece(3)", "onepiece"}));
	printVector(solution.getFolderNames(vector<string>{"wano", "wano", "wano", "wano"}));
	printVector(solution.getFolderNames(vector<string>{"kaido", "kaido(1)", "kaido", "kaido(1)"}));
	printVector(solution.getFolderNames(vector<string>{"kaido", "kaido(1)", "kaido", "kaido(1)", "kaido(2)"	}));
	printVector(solution.getFolderNames(vector<string>{"kaido", "kaido(1)", "kaido", "kaido(1)", "kaido(2)(1)", "kaido(2)"}));
}