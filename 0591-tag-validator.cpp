#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool isValid(string code) {
		int n = code.size();
		stack<string> tags;
		int i = 0;
		while (i < n) {
			if (code[i] == '<') {
				if (i == n - 1) {
					return false;
				}
				if(code[i + 1] == '/') {
					int j = code.find('>', i);
					if (j == string::npos) {
						return false;
					}
					string tagName = code.substr(i + 2, j - (i + 2));
					if (tags.empty() || tags.top() != tagName) {
						return false;
					}
					tags.pop();
					i = j + 1;
					if (tags.empty() && i != n ) {
						return false;
					}
				}
				else if (code[i + 1] == '!') {
					if (tags.empty()) {
						return false;
					}
					if (code.substr(i + 2, 7) != "[CDATA[") {
						return false;
					}
					int j = code.find("]]>", i + 9);
					if (j == string::npos) {
						return false;
					}
					i = j + 1;
				}
				else {
					int j = code.find('>', i);
					if (j == string::npos || j - i == 1 || j - i > 10) {
						return false;
					}
					string tagName = code.substr(i + 1, j - (i + 1));
					if (!all_of(tagName.begin(), tagName.end(), [](unsigned char c) {return isupper(c); })) {
						return false;
					}
					tags.push(move(tagName));
					i = j + 1;
				}
			}
			else {
				if (tags.empty()) {
					return false;
				}
				++i;
			}
		}

		return tags.empty();
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>") << endl;
	cout << solution.isValid("<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>") << endl;
	cout << solution.isValid("<A>  <B> </A>   </B>") << endl;
	cout << solution.isValid("<DIV>  div tag is not closed  <DIV>") << endl;
	cout << solution.isValid("<DIV>  unmatched <  </DIV>") << endl;
	cout << solution.isValid("<DIV> closed tags with invalid tag name  <b>123</b> </DIV>") << endl;
	cout << solution.isValid("<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>") << endl;
	cout << solution.isValid("<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>") << endl;
	cout << solution.isValid("<DIV><></></DIV>") << endl;
	cout << solution.isValid("<DIV><YFSYYS><UVBNIQ><XPMXUNT><WNGMV><OJJGQREMT><Z><GEJDP><LIQS><NCVYU><RAS><UYFKCJCDN><NA><POJVYT><Z><TDC><VUIZQC><BNANGX><TOF><MR>MK</MR></TOF></BNANGX></VUIZQC></TDC></Z></POJVYT></NA></UYFKCJCDN></RAS></NCVYU></LIQS></GEJDP></Z></OJJGQREMT></WNGMV></XPMXUNT></UVBNIQ></YFSYYS></DIV>") << endl;
}
