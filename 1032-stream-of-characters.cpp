#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TrieNode {
	vector<TrieNode *> children;
	bool isEnd;
	TrieNode *fail;
	TrieNode() {
		this->children = vector<TrieNode *>(26, nullptr);
		this->isEnd = false;
		this->fail = nullptr;
	}
};

class StreamChecker {
public:
	TrieNode *root;
	TrieNode *temp;
	StreamChecker(vector<string>& words) {
		root = new TrieNode();
		for (string &word : words) {
			TrieNode *cur = root;
			for (int i = 0; i < word.size(); i++) {
				int index = word[i] - 'a';
				if (cur->children[index] == nullptr) {
					cur->children[index] = new TrieNode();
				}
				cur = cur->children[index];
			}
			cur->isEnd = true;
		}
		root->fail = root;
		queue<TrieNode *> q;
		for (int i = 0; i < 26; i++) {
			if (root->children[i] != nullptr) {
				root->children[i]->fail = root;
				q.emplace(root->children[i]);
			}
			else {
				root->children[i] = root;
			}
		}
		while (!q.empty()) {
			TrieNode *node = q.front();
			q.pop();
			node->isEnd = node->isEnd || node->fail->isEnd;
			for (int i = 0; i < 26; i++) {
				if (node->children[i] != nullptr) {
					node->children[i]->fail = node->fail->children[i];
					q.emplace(node->children[i]);
				}
				else {
					node->children[i] = node->fail->children[i];
				}
			}
		}

		temp = root;
	}

	bool query(char letter) {
		temp = temp->children[letter - 'a'];
		return temp->isEnd;
	}
};

int main(void){
	StreamChecker streamChecker = StreamChecker(vector<string>{ "cd", "f", "kl" });
	cout << streamChecker.query('a'); // ���� False
	cout << streamChecker.query('b'); // ���� False
	cout << streamChecker.query('c'); // ����n False
	cout << streamChecker.query('d'); // ���� True ����Ϊ 'cd' �� words ��
	cout << streamChecker.query('e'); // ���� False
	cout << streamChecker.query('f'); // ���� True ����Ϊ 'f' �� words ��
	cout << streamChecker.query('g'); // ���� False
	cout << streamChecker.query('h'); // ���� False
	cout << streamChecker.query('i'); // ���� False
	cout << streamChecker.query('j'); // ���� False
	cout << streamChecker.query('k'); // ���� False
	cout << streamChecker.query('l'); // ���� True ����Ϊ 'kl' �� words ��
}
