#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		unordered_set<string> uaddrs;
		for (auto &email : emails) {
			string actual = "";
			for (int i = 0; i < email.size(); i++) {
				if (email[i] == '@') {
					actual += email.substr(i);
					break;
				}
				if (email[i] == '+') {
					int domain = email.find('@');
					actual += email.substr(domain);
					break;
				}
				if (email[i] != '.') {
					actual += email[i];
				}
			}
			uaddrs.insert(actual);
		}
		return uaddrs.size();
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.numUniqueEmails(vector<string> {"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"}) << endl;
	cout << solution.numUniqueEmails(vector<string> {"a@leetcode.com", "b@leetcode.com", "c@leetcode.com"}) << endl;
}
