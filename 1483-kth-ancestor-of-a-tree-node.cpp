#include <iostream>
#include <vector>
using namespace std;

class TreeAncestor {
	const static int Log = 16;
	vector<vector<int>> ancestors;

public:
	TreeAncestor(int n, vector<int>& parent) {
		ancestors = vector<vector<int>>(n, vector<int>(Log, -1));
		for (int i = 0; i < n; i++) {
			ancestors[i][0] = parent[i];
		}
		for (int j = 1; j < Log; j++) {
			for (int i = 0; i < n; i++) {
				if (ancestors[i][j - 1] != -1) {
					ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1];
				}
			}
		}
	}

	int getKthAncestor(int node, int k) {
		for (int j = 0; j < Log; j++) {
			if ((k >> j) & 1) {
				node = ancestors[node][j];
				if (node == -1) {
					return -1;
				}
			}
		}
		return node;
	}
};

int main(void){
	TreeAncestor treeAncestor = TreeAncestor(7, vector<int>{-1, 0, 0, 1, 1, 2, 2});
	cout << treeAncestor.getKthAncestor(3, 1) << endl;  // ���� 1 ������ 3 �ĸ��ڵ�
	cout << treeAncestor.getKthAncestor(5, 2) << endl;  // ���� 0 ������ 5 ���游�ڵ�
	cout << treeAncestor.getKthAncestor(6, 3) << endl;  // ���� -1 ��Ϊ����������Ҫ������Ƚڵ�
}
