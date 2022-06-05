#include <iostream>
#include <vector>
#include <random>
using namespace std;

class Solution{
	mt19937 gen{ random_device{}() };
	uniform_real_distribution<double> dis;
	double radius, x_center, y_center;
public:
	Solution(double radius, double x_center, double y_center) : dis(-radius, radius), radius(radius), x_center(x_center), y_center(y_center) {}

	vector<double> randPoint() {
		while (true) {
			double x = dis(gen), y = dis(gen);
			if (x*x + y*y <= radius*radius) {
				return{ x_center + x, y_center + y };
			}
		}
	}
};

template<typename T>
void printVector(const vector<T> &v){
	for (auto &e : v) cout << e << ", ";
	cout << endl;
}

int main(void){
	Solution solution = Solution(1.0, 0.0, 0.0);
	for (int i = 0; i < 10; i++)
		printVector(solution.randPoint());
}
