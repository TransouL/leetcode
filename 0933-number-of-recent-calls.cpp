#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class RecentCounter {
	vector<int> req;
	int head = 0;
public:
	RecentCounter() {
	}

	int ping(int t) {
		req.push_back(t);
		head = lower_bound(req.begin() + head, req.end(), t - 3000) - req.begin();
		return req.size() - head;
	}
};

int main(void){
	RecentCounter cnt = RecentCounter();
	cout << cnt.ping(1) << endl;
	cout << cnt.ping(100) << endl;
	cout << cnt.ping(3001) << endl;
	cout << cnt.ping(3002) << endl;
}
