#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		int n1 = list1.size(), n2 = list2.size(), ansCount = n1 + n2;
		vector<string> ans;
		for (int i = 0; i < n1 && i <= ansCount; i++) {
			auto idx2 = find(list2.begin(), list2.end(), list1[i]);
			if (idx2 != list2.end()) {
				int currCount = i + (idx2 - list2.begin());
				if (ansCount > currCount) {
					ansCount = currCount;
					ans.clear();
					ans.emplace_back(list1[i]);
				}
				else if (ansCount == currCount) {
					ans.emplace_back(list1[i]);
				}
			}
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
	printVector(solution.findRestaurant(vector<string>{"Shogun", "Tapioca Express", "Burger King", "KFC"}, vector<string> {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"}));
	printVector(solution.findRestaurant(vector<string>{"Shogun", "Tapioca Express", "Burger King", "KFC"}, vector<string> {"KFC", "Shogun", "Burger King"}));
}
