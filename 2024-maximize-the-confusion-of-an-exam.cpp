#include <iostream>

using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))

class Solution {
	int maxConsecutiveAnswers(string &answerKey, int k, char ch) {
		int n = answerKey.length();
		int left = 0, right = 0, sum = 0;

		while (right < n && sum < k) {
			sum += answerKey[right++] != ch;
		}
		int ans = right < n ? right : n;

		while (right < n) {
			if (answerKey[right] != ch) {
				while (answerKey[left] == ch) {
					++left;
				}
				++left;
			}
			ans = max(ans, right - left + 1);
			right++;
		}
		return ans;
	}
public:
	int maxConsecutiveAnswers(string answerKey, int k) {
		int a1 = maxConsecutiveAnswers(answerKey, k, 'T');
		int a2 = maxConsecutiveAnswers(answerKey, k, 'F');
		return max(a1, a2);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.maxConsecutiveAnswers("TTFF", 2) << endl;
	cout << solution.maxConsecutiveAnswers("TFFT", 1) << endl;
	cout << solution.maxConsecutiveAnswers("TTFTTFTT", 1) << endl;
}
