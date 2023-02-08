#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class AuthenticationManager {
	int timeToLive;
	unordered_map<string, int> validity;

public:
	AuthenticationManager(int timeToLive) {
		this->timeToLive = timeToLive;
	}

	void generate(string tokenId, int currentTime) {
		validity.emplace(tokenId, currentTime + timeToLive);
	}

	void renew(string tokenId, int currentTime) {
		if (validity.count(tokenId)) {
			if (validity[tokenId] > currentTime) {
				validity[tokenId] = currentTime + timeToLive;
			}
			else {
				validity.erase(tokenId);
			}
		}
	}

	int countUnexpiredTokens(int currentTime) {
		vector<string> expired;
		for (auto &p : validity) {
			if (p.second <= currentTime) {
				expired.push_back(p.first);
			}
		}
		for (auto &k : expired) {
			validity.erase(k);
		}
		return validity.size();
	}
};

int main(void){
	AuthenticationManager authenticationManager = AuthenticationManager(5);
	authenticationManager.renew("aaa", 1); // ʱ�� 1 ʱ��û����֤��� tokenId Ϊ "aaa" ��û����֤�뱻���¡�
	authenticationManager.generate("aaa", 2); // ʱ�� 2 ʱ������һ�� tokenId Ϊ "aaa" ������֤�롣
	cout << authenticationManager.countUnexpiredTokens(6) << endl; // ʱ�� 6 ʱ��ֻ�� tokenId Ϊ "aaa" ����֤��δ���ڣ����Է��� 1 ��
	authenticationManager.generate("bbb", 7); // ʱ�� 7 ʱ������һ�� tokenId Ϊ "bbb" ������֤�롣
	authenticationManager.renew("aaa", 8); // tokenId Ϊ "aaa" ����֤����ʱ�� 7 ���ڣ��� 8 >= 7 ������ʱ�� 8 ��renew ���������ԣ�û����֤�뱻���¡�
	authenticationManager.renew("bbb", 10); // tokenId Ϊ "bbb" ����֤����ʱ�� 10 û�й��ڣ����� renew ������ִ�У��� token ����ʱ�� 15 ���ڡ�
	cout << authenticationManager.countUnexpiredTokens(15) << endl; // tokenId Ϊ "bbb" ����֤����ʱ�� 15 ���ڣ�tokenId Ϊ "aaa" ����֤����ʱ�� 7 ���ڣ�������֤����ѹ��ڣ����Է��� 0 ��
}
