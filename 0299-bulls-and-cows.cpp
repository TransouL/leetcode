#include <iostream>
#include <string>

#define min(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		int aCount = 0, bCount = 0, secretB[10] = { 0 }, guessB[10] = { 0 };

		for (size_t i = 0; i < secret.length(); i++){
			if (secret[i] == guess[i]){
				++aCount;
			}
			else {
				++secretB[secret[i] - '0'];
				++guessB[guess[i] - '0'];
			}
		}
		for (size_t i = 0; i < 10; i++){
			bCount += min(secretB[i], guessB[i]);
		}

		return to_string(aCount) + "A" + to_string(bCount) + "B";
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.getHint("1807", "7810") << endl;
	cout << solution.getHint("1123", "0111") << endl;
	cout << solution.getHint("1", "0") << endl;
	cout << solution.getHint("1", "1") << endl;
}
