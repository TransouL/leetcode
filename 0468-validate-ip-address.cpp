#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string validIPAddress(string queryIP) {
		if (queryIP.find('.') != string::npos) {
			int last = -1;
			for (int i = 0; i < 4; i++) {
				int curr = i == 3 ? queryIP.size() : queryIP.find('.', last + 1);
				if (curr == string::npos)
					return "Neither";
				if (curr - last - 1 < 1 || curr - last - 1 > 3)
					return "Neither";
				int addr = 0;
				for (int j = last + 1; j < curr; j++) {
					if (!isdigit(queryIP[j]))
						return "Neither";
					addr = addr * 10 + (queryIP[j] - '0');
				}
				if (addr > 255)
					return "Neither";
				if (addr > 0 && queryIP[last + 1] == '0')
					return "Neither";
				if (addr == 0 && curr - last - 1 > 1)
					return "Neither";
				last = curr;
			}
			return "IPv4";
		}
		else {
			int last = -1;
			for (int i = 0; i < 8; i++) {
				int curr = i == 7 ? queryIP.size() : queryIP.find(':', last + 1);
				if (curr == string::npos)
					return "Neither";
				if (curr - last - 1 < 1 || curr - last - 1 > 4)
					return "Neither";
				for (int j = last + 1; j < curr; j++) {
					char ch = queryIP[j];
					if (!isdigit(ch) && ('a' > tolower(ch) || tolower(ch) > 'f'))
						return "Neither";
				}
				last = curr;
			}
			return "IPv6";
		}
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.validIPAddress("172.16.254.1") << endl;
	cout << solution.validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334") << endl;
	cout << solution.validIPAddress("256.256.256.256") << endl;
}
