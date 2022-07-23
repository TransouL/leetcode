#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
		if (start == destination) {
			return 0;
		}
		int begin = min(start, destination), end = max(start, destination);
		int total = 0, foward = 0;
		for (int i = 0; i < distance.size(); i++) {
			auto &dis = distance[i];
			total += dis;
			if (begin != 0 && i == begin - 1) {
				foward = total;
			}
			else if (i == end - 1) {
				foward = total - foward;
			}
		}
		return min(foward, total - foward);
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.distanceBetweenBusStops(vector<int>{1, 2, 3, 4 }, 0, 1) << endl;
	cout << solution.distanceBetweenBusStops(vector<int>{1, 2, 3, 4 }, 0, 2) << endl;
	cout << solution.distanceBetweenBusStops(vector<int>{1, 2, 3, 4 }, 0, 3) << endl;
}
