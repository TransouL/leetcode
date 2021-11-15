#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

struct hash_pair {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const{
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);
		return hash1 ^ hash2;
	}
};

class Solution {
public:
	bool isRectangleCover(vector<vector<int>>& rectangles) {
		long area = 0;
		int minX = 100000, minY = 100000, maxX = -100000, maxY = -100000;
		unordered_map<pair<int, int>, int, hash_pair> cnts;
		for (auto &rect : rectangles){
			int x = rect[0], y = rect[1], a = rect[2], b = rect[3];

			area += (long)(a - x) * (b - y);

			minX = min(minX, x);
			minY = min(minY, y);
			maxX = max(maxX, a);
			maxY = max(maxY, b);

			cnts[{x, y}] += 1;
			cnts[{x, b}] += 1;
			cnts[{a, y}] += 1;
			cnts[{a, b}] += 1;
		}

		if (area != (long)(maxX - minX) * (maxY - minY))
			return false;
		
		if (cnts[{ minX, minY }] != 1)
			return false;
		else
			cnts.erase({ minX, minY });
		if (cnts[{ minX, maxY }] != 1)
			return false;
		else
			cnts.erase({ minX, maxY });
		if (cnts[{ maxX, minY }] != 1)
			return false;
		else
			cnts.erase({ maxX, minY });
		if (cnts[{ maxX, maxY }] != 1)
			return false;
		else
			cnts.erase({ maxX, maxY });

		for (auto &entry : cnts){
			if (entry.second != 2 && entry.second != 4)
				return false;
		}
		return true;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.isRectangleCover(vector<vector<int>>{ { 1, 1, 3, 3 }, { 3, 1, 4, 2 }, { 3, 2, 4, 4 }, { 1, 3, 2, 4 }, { 2, 3, 3, 4 } }) << endl;
	cout << solution.isRectangleCover(vector<vector<int>>{ { 1, 1, 2, 3 }, { 1, 3, 2, 4 }, { 3, 1, 4, 2 }, { 3, 2, 4, 4 } }) << endl;
	cout << solution.isRectangleCover(vector<vector<int>>{ { 1, 1, 3, 3 }, { 3, 1, 4, 2 }, { 1, 3, 2, 4 }, { 3, 2, 4, 4 } }) << endl;
	cout << solution.isRectangleCover(vector<vector<int>>{ { 1, 1, 3, 3 }, { 3, 1, 4, 2 }, { 1, 3, 2, 4 }, { 2, 2, 4, 4 } }) << endl;
}