#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<double> convertTemperature(double celsius) {
		return{ celsius + 273.15, celsius * 1.80 + 32.00 };
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.convertTemperature(36.50));
	printVector(solution.convertTemperature(122.11));
}