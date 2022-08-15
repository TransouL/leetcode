#include <iostream>
using namespace std;

struct Node {
	int val;
	Node *prev, *next;
	Node() : val(0), prev(nullptr), next(nullptr) {}
	Node(int x) : val(x), prev(nullptr), next(nullptr) {}
	Node(int x, Node *prev, Node *next) : val(x), prev(prev), next(next) {}
};

class MyCircularDeque {
	int size, curr;
	Node *head, *tail;

public:
	MyCircularDeque(int k) {
		size = k;
		curr = 0;
	}

	bool insertFront(int value) {
		if (curr == size)
			return false;
		if (curr == 0) {
			head = tail = new Node(value);
		}
		else {
			Node *node = new Node(value, nullptr, head);
			head->prev = node;
			head = node;
		}
		++curr;
		return true;
	}

	bool insertLast(int value) {
		if (curr == size)
			return false;
		if (curr == 0) {
			head = tail = new Node(value);
		}
		else {
			Node *node = new Node(value, tail, nullptr);
			tail->next = node;
			tail = node;
		}
		++curr;
		return true;
	}

	bool deleteFront() {
		if (curr == 0)
			return false;
		--curr;
		if (curr > 0) {
			head = head->next;
			head->prev = nullptr;
		}
		return true;
	}

	bool deleteLast() {
		if (curr == 0)
			return false;
		--curr;
		if (curr > 0) {
			tail = tail->prev;
			tail->next = nullptr;
		}
		return true;
	}

	int getFront() {
		if (curr == 0)
			return -1;
		return head->val;
	}

	int getRear() {
		if (curr == 0)
			return -1;
		return tail->val;
	}

	bool isEmpty() {
		return curr == 0;
	}

	bool isFull() {
		return curr == size;
	}
};

int main(void){
	MyCircularDeque circularDeque = MyCircularDeque(3); // ����������СΪ3
	cout << circularDeque.insertLast(1) << endl;			        // ���� true
	cout << circularDeque.insertLast(2) << endl;			        // ���� true
	cout << circularDeque.insertFront(3) << endl;			        // ���� true
	cout << circularDeque.insertFront(4) << endl;			        // �Ѿ����ˣ����� false
	cout << circularDeque.getRear() << endl;  				// ���� 2
	cout << circularDeque.isFull() << endl;				        // ���� true
	cout << circularDeque.deleteLast() << endl;			        // ���� true
	cout << circularDeque.insertFront(4) << endl;			        // ���� true
	cout << circularDeque.getFront() << endl;				// ���� 4
}
