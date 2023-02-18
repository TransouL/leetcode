#include <iostream>
#include <vector>
using namespace std;

// This is the custom function interface.
// You should not implement it, or speculate about its implementation
class CustomFunction {
public:
	// Returns f(x, y) for any given positive integers x and y.
	// Note that f(x, y) is increasing with respect to both x and y.
	// i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
	int f(int x, int y) {
		return x + y;
	};
};

class Solution {
public:
	vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
		vector<vector<int>> ans;
		for (int x = 1, y = 1000; x <= 1000 && y >= 1; x++) {
			while (y >= 1 && customfunction.f(x, y) > z) {
				y--;
			}
			if (y >= 1 && customfunction.f(x, y) == z) {
				ans.push_back({ x, y });
			}
		}
		return ans;
	}
};

template<typename T>
void printVector(const vector<vector<T>> &v){
	for (auto &e : v) {
		for (auto &i : e)
			cout << i << ", ";
		cout << endl;
	}
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	CustomFunction customfunction = CustomFunction();
	printVector(solution.findSolution(customfunction, 5));
}