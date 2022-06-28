#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		return longUrl;
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		return shortUrl;
	}
};

int main(void){
	Solution solution = Solution();
	string tiny = solution.encode("https://leetcode.com/problems/design-tinyurl"); // 返回加密后得到的 TinyURL 。
	string orig = solution.decode(tiny); // 返回解密后得到的原本的 URL 。
	cout << tiny << endl;
	cout << orig << endl;
}