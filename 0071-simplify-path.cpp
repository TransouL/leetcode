#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	void handle(string &path, vector<string> &folders, int &left, int &right){
		string folder = path.substr(left, right - left);
		if (folder == "..") {
			if (!folders.empty()) {
				folders.pop_back();
			}
		}
		else if (folder != ".") {
			folders.emplace_back(move(folder));
		}
	}

	string simplifyPath(string path) {
		vector<string> folders;
		int n = path.length(), left = 0, right = 0;
		for (int i = 0; i < n; i++) {
			if (path[i] == '/'){
				if (left != right)
					handle(path, folders, left, right);
				left = right = i + 1;
			}
			else {
				++right;
			}
		}
		if (left != right)
			handle(path, folders, left, right);

		string ans = folders.empty() ? "/" : "";
		for (auto &folder : folders) {
			ans += "/" + move(folder);
		}
		return ans;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.simplifyPath("/home/") << endl;
	cout << solution.simplifyPath("/../") << endl;
	cout << solution.simplifyPath("/home//foo/") << endl;
	cout << solution.simplifyPath("/a/./b/../../c/") << endl;
}
