#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
	int size, head, curr;
	vector<int> data;

public:
	MyCircularQueue(int k) {
		data.resize(k);
		size = k;
		head = 0;
		curr = 0;
	}

	bool enQueue(int value) {
		if (curr == size)
			return false;
		data[(head + curr++) % size] = value;
		return true;
	}

	bool deQueue() {
		if (curr == 0)
			return false;
		head = (head + 1) % size;
		--curr;
		return true;
	}

	int Front() {
		return isEmpty() ? -1 : data[head];
	}

	int Rear() {
		return isEmpty() ? -1 : data[(head + curr - 1) % size];
	}

	bool isEmpty() {
		return curr == 0;
	}

	bool isFull() {
		return curr == size;
	}
};

int main(void){
	MyCircularQueue circularQueue = MyCircularQueue(3); // ���ó���Ϊ 3
	cout << circularQueue.enQueue(1) << endl;  // ���� true
	cout << circularQueue.enQueue(2) << endl;  // ���� true
	cout << circularQueue.enQueue(3) << endl;  // ���� true
	cout << circularQueue.enQueue(4) << endl;  // ���� false����������
	cout << circularQueue.Rear() << endl;  // ���� 3
	cout << circularQueue.isFull() << endl;  // ���� true
	cout << circularQueue.deQueue() << endl;  // ���� true
	cout << circularQueue.enQueue(4) << endl;  // ���� true
	cout << circularQueue.Rear() << endl;  // ���� 4
}
