#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;

struct Trie {
	Trie() : ref(-1) {}
	unordered_map<string, Trie*> children;
	int ref;
};

class Solution {
public:
	vector<string> removeSubfolders(vector<string>& folder) {
		auto split = [](const string &s) -> vector<string> {
			vector<string> ret;
			string cur;
			for (auto &ch : s) {
				if (ch == '/') {
					ret.push_back(move(cur));
					cur.clear();
				}
				else {
					cur.push_back(ch);
				}
			}
			ret.push_back(move(cur));
			return ret;
		};
		
		Trie root = Trie();
		for (int i = 0; i < folder.size(); i++) {
			vector<string> path = split(folder[i]);
			Trie *curr = &root;
			for (auto &name : path) {
				if (!curr->children.count(name)) {
					curr->children[name] = new Trie();
				}
				curr = curr->children[name];
			}
			curr->ref = i;
		}

		vector<string> ans;
		function<void(Trie *)> dfs = [&](Trie *curr) {
			if (curr->ref != -1) {
				ans.push_back(folder[curr->ref]);
				return;
			}
			for (auto &&p : curr->children) {
				dfs(p.second);
			}
		};

		dfs(&root);
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
	printVector(solution.removeSubfolders(vector<string> {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"}));
	printVector(solution.removeSubfolders(vector<string> {"/a", "/a/b/c", "/a/b/d"}));
	printVector(solution.removeSubfolders(vector<string> {"/a/b/c", "/a/b/ca", "/a/b/d"}));
}