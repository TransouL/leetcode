#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Trie {
private:
	vector<Trie *> children;
	bool isEnd;

public:
	Trie() : children(26), isEnd(false) {}

	void insert(string word) {
		Trie *node = this;
		for (char ch : word) {
			ch -= 'a';
			if (node->children[ch] == nullptr) {
				node->children[ch] = new Trie();
			}
			node = node->children[ch];
		}
		node->isEnd = true;
	}

	bool isConcatenated(const string &word, int start, vector<int> &visited) {
		if (word.size() == start)
			return true;
		if (visited[start])
			return false;
		visited[start] = true;
		Trie *node = this;
		for (int i = start; i < word.size(); i++) {
			int idx = word[i] - 'a';
			node = node->children[idx];
			if (node == nullptr)
				return false;
			if (node->isEnd)
				if (isConcatenated(word, i + 1, visited)) {
					return true;
				}
		}
		return false;
	}

	bool isConcatenated(const string &word, int start = 0) {
		vector<int> visited((word.size() - start), 0);
		return isConcatenated(word, start, visited);
	}
};

class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		Trie trie = Trie();
		sort(words.begin(), words.end(), [&](const string &a, const string &b) {return a.size() < b.size(); });
		vector<string> ans;
		for (auto &word : words) {
			if (word.empty())
				continue;
			if (trie.isConcatenated(word))
				ans.emplace_back(word);
			else
				trie.insert(word);
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
	printVector(solution.findAllConcatenatedWordsInADict(vector<string> {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"}));
	printVector(solution.findAllConcatenatedWordsInADict(vector<string> {"cat", "dog", "catdog"}));
}
