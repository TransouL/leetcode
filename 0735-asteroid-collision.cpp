#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> left, right;
		for (auto & v : asteroids) {
			if (v > 0) {
				right.push_back(v);
			}
			else {
				bool isExplode = false;
				while (!right.empty()) {
					if (-v < right.back()) {
						isExplode = true;
						break;
					}
					else if (-v == right.back()) {
						isExplode = true;
						right.pop_back();
						break;
					}
					else {
						right.pop_back();
					}
				}
				if (!isExplode) {
					left.push_back(v);
				}
			}
		}
		left.insert(left.end(), right.begin(), right.end());
		return left;
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution();
	printVector(solution.asteroidCollision(vector<int>{ 5, 10, -5 }));
	printVector(solution.asteroidCollision(vector<int>{ 8, -8 }));
	printVector(solution.asteroidCollision(vector<int>{ 10, 2, -5 }));
}
