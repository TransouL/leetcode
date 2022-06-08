#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

class Solution {
	mt19937 gen{ random_device{}() };
	uniform_int_distribution<int> dis;
	vector<vector<int>> &rects;
	vector<int> points;
public:
	Solution(vector<vector<int>>& rects) : rects(rects) {
		int pointsCount = 0;
		for (auto &rect : rects) {
			pointsCount += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
			points.push_back(pointsCount);
		}
		dis = uniform_int_distribution<int> {1, pointsCount};
	}

	vector<int> pick() {
		int point = dis(gen);
		int idx = lower_bound(points.begin(), points.end(), point) - points.begin();
		int offset = (idx == 0 ? point : point - points[idx - 1]) - 1;
		vector<int> rect = rects[idx];
		int w = rect[2] - rect[0] + 1;
		return{ rect[0] + offset % w, rect[1] + offset / w };
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	vector<vector<int>> rects = { { -2, -2, 1, 1 }, { 2, 2, 4, 6 } };
	Solution solution = Solution(rects);
	for (int i = 0; i < 10; i++)
		printVector(solution.pick());
}
