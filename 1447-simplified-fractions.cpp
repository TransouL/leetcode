#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
	int gcd(int a, int b){
		int r;
		while (a%b != 0){
			r = a%b;
			a = b;
			b = r;
		}
		return b;
	}

public:
	vector<string> simplifiedFractions(int n) {
		vector<string> ans;
		if (n > 1) {
			ans.emplace_back("1/2");
		}
		
		for (int i = 3; i <= n; i++){
			ans.emplace_back("1/" + to_string(i));
			for (int j = 2; j < i - 1; j++) {
				if (gcd(i, j) == 1) {
					ans.emplace_back(to_string(j) + "/" + to_string(i));
				}
			}
			ans.emplace_back(to_string(i - 1) + "/" + to_string(i));
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
	printVector(solution.simplifiedFractions(1));
	printVector(solution.simplifiedFractions(2));
	printVector(solution.simplifiedFractions(3));
	printVector(solution.simplifiedFractions(4));
}
