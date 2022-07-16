#include <iostream>
#include <queue>
using namespace std;

class MovingAverage {
	queue<int> nums;
	double sum = 0.0;
	int size;

public:
	/** Initialize your data structure here. */
	MovingAverage(int size) {
		this->size = size;
	}

	double next(int val) {
		if (nums.size() == size) {
			int head = nums.front();
			nums.pop();
			sum -= head;
		}
		nums.emplace(val);
		sum += val;
		return sum / nums.size();
	}
};

int main(void){
	MovingAverage movingAverage = MovingAverage(3);
	cout << movingAverage.next(1) << endl;// 返回 1.0 = 1 / 1
	cout << movingAverage.next(10) << endl; // 返回 5.5 = (1 + 10) / 2
	cout << movingAverage.next(3) << endl; // 返回 4.66667 = (1 + 10 + 3) / 3
	cout << movingAverage.next(5) << endl; // 返回 6.0 = (10 + 3 + 5) / 3
}

