#include <iostream>
#include <unordered_map>

using namespace std;

struct TrieNode {
	int val;
	TrieNode *next[26];
	TrieNode() : val(0) {
		for (int i = 0; i < 26; ++i) {
			this->next[i] = nullptr;
		}
	}
};

class MapSum {
public:
	MapSum() {
		this->root = new TrieNode();
	}

	void insert(string key, int val) {
		TrieNode *curr = root;
		for (auto c : key) {
			if (curr->next[c - 'a'] == nullptr)
				curr->next[c - 'a'] = new TrieNode();
			curr = curr->next[c - 'a'];
		}
		curr->val = val;
	}

	int sum(string prefix) {
		TrieNode *curr = root;
		for (auto c : prefix) {
			if (curr->next[c - 'a'] == nullptr)
				return 0;
			else
				curr = curr->next[c - 'a'];
		}
		return sum(curr);
	}

private:
	TrieNode *root;
	int sum(TrieNode *node) {
		int ret = node->val;
		for (auto p : node->next) {
			if (p != nullptr)
				ret += sum(p);
		}
		return ret;
	}
};

int main(void){
	MapSum *mapSum = new MapSum();
	mapSum->insert("apple", 3);
	cout << mapSum->sum("ap") << endl; // return 3 (apple = 3)
	mapSum->insert("app", 2);
	cout << mapSum->sum("ap") << endl; // return 5 (apple + app = 3 + 2 = 5)
}