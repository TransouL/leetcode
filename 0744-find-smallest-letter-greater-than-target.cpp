#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		return target < letters.back() ? *upper_bound(letters.begin(), letters.end() - 1, target) : letters[0];
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.nextGreatestLetter(vector<char> {'c', 'f', 'j'}, 'a') << endl;
	cout << solution.nextGreatestLetter(vector<char> {'c', 'f', 'j'}, 'c') << endl;
	cout << solution.nextGreatestLetter(vector<char> {'c', 'f', 'j'}, 'd') << endl;
	cout << solution.nextGreatestLetter(vector<char> {'c', 'f', 'j'}, 'j') << endl;
}
