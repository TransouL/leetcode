#include <iostream>
#include <vector>
#include <string>
using namespace std;

class OrderedStream {
	vector<string> data;
	int n, ptr;

public:
	OrderedStream(int n) {
		this->n = n;
		data.resize(n + 1);
		ptr = 1;
	}

	vector<string> insert(int idKey, string value) {
		data[idKey] = value;
		if (idKey == ptr) {
			vector<string> ans;
			ans.push_back(value);
			while (++ptr <= n && !data[ptr].empty()) {
				ans.push_back(data[ptr]);
			}
			return ans;
		}
		else {
			return {};
		}
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	OrderedStream os = OrderedStream(5);
	printVector(os.insert(3, "ccccc")); // ���� (3, "ccccc")������ []
	printVector(os.insert(1, "aaaaa")); // ���� (1, "aaaaa")������ ["aaaaa"]
	printVector(os.insert(2, "bbbbb")); // ���� (2, "bbbbb")������ ["bbbbb", "ccccc"]
	printVector(os.insert(5, "eeeee")); // ���� (5, "eeeee")������ []
	printVector(os.insert(4, "ddddd")); // ���� (4, "ddddd")������ ["ddddd", "eeeee"]
}
