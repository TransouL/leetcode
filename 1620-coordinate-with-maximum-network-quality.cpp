#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	int getSquaredDistance(const int &x, const int &y, const vector<int> &tower) {
		return (tower[0] - x) * (tower[0] - x) + (tower[1] - y) * (tower[1] - y);
	}
public:
	vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
		int xMax = INT_MIN, yMax = INT_MIN;
		for (auto &&tower : towers) {
			xMax = max(xMax, tower[0]);
			yMax = max(yMax, tower[1]);
		}
		int cx = 0, cy = 0, maxQuality = 0, squaredRadius = radius * radius;
		for (int x = 0; x <= xMax; x++) {
			for (int y = 0; y <= yMax; y++) {
				int quality = 0;
				for (auto &&tower : towers) {
					int squairedDistance = getSquaredDistance(x, y, tower);
					if (squairedDistance <= squaredRadius) {
						double distance = sqrt((double)squairedDistance);
						quality += floor((double)tower[2] / (1 + distance));
					}
				}
				if (quality > maxQuality) {
					cx = x;
					cy = y;
					maxQuality = quality;
				}
			}
		}
		return{ cx, cy };
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void) {
	Solution solution = Solution();
	printVector(solution.bestCoordinate(vector<vector<int>> { {1, 2, 5}, { 2, 1, 7 }, { 3, 1, 9 } }, 2));
	printVector(solution.bestCoordinate(vector<vector<int>> { {23, 11, 21 } }, 9));
	printVector(solution.bestCoordinate(vector<vector<int>> { {1, 2, 13}, { 2, 1, 7 }, { 0, 1, 9 } }, 2));
}

