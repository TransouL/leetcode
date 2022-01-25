#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int matrix[1001][1001];

class DetectSquares {
public:
	DetectSquares() {
		memset(matrix, 0, sizeof(matrix));
	}

	void add(vector<int> point) {
		++matrix[point[0]][point[1]];
	}

	int count(vector<int> point) {
		int ans = 0;
		int x = point[0], y = point[1];
		for (int i = 0; i < 1001; i++) {
			if (i != x && matrix[i][y]) {
				int edge = abs(x - i);
				if (0 <= y - edge && matrix[i][y - edge] && matrix[x][y - edge]) {
					ans += matrix[i][y] * matrix[i][y - edge] * matrix[x][y - edge];
				}
				if (y + edge < 1001 && matrix[i][y + edge] && matrix[x][y + edge]) {
					ans += matrix[i][y] * matrix[i][y + edge] * matrix[x][y + edge];
				}
			}
		}
		return ans;
	}
};

int main(void) {
	DetectSquares detectSquares = DetectSquares();
	detectSquares.add({ 3, 10 });
	detectSquares.add({ 11, 2 });
	detectSquares.add({ 3, 2 });
	cout << detectSquares.count({ 11, 10 }) << endl; // 返回 1 。你可以选择：- 第一个，第二个，和第三个点
	cout << detectSquares.count({ 14, 8 }) << endl;  // 返回 0 。查询点无法与数据结构中的这些点构成正方形。
	detectSquares.add({ 11, 2 });    // 允许添加重复的点。
	cout << detectSquares.count({ 11, 10 }) << endl; // 返回 2 。你可以选择：
	//   - 第一个，第二个，和第三个点
	//   - 第一个，第三个，和第四个点
}
