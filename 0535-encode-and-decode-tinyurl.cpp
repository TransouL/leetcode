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
	string tiny = solution.encode("https://leetcode.com/problems/design-tinyurl"); // ���ؼ��ܺ�õ��� TinyURL ��
	string orig = solution.decode(tiny); // ���ؽ��ܺ�õ���ԭ���� URL ��
	cout << tiny << endl;
	cout << orig << endl;
}