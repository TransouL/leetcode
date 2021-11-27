#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	Solution(int m, int n) {
		this->m = m, this->n = n, this->curr = m * n;
	}

	vector<int> flip() {
		int x = rand() % curr;
		vector<int> ans;
		--curr;
		if (map.count(x))
			ans = { map[x] / n, map[x] % n };
		else
			ans = { x / n, x %n };
		if (map.count(curr))
			map[x] = map[curr];
		else
			map[x] = curr;
		return ans;
	}

	void reset() {
		curr = m * n;
		map.clear();
	}
private:
	int m, n, curr;
	unordered_map<int, int> map;
};

int main(void){
	Solution solution = Solution(3, 1);
	vector<int> pos = solution.flip();
	cout << pos[0] << ", " << pos[1] << endl;
	pos = solution.flip();
	cout << pos[0] << ", " << pos[1] << endl;
	pos = solution.flip();
	cout << pos[0] << ", " << pos[1] << endl;
	solution.reset();
	pos = solution.flip();
	cout << pos[0] << ", " << pos[1] << endl;
}