#include <iostream>
using namespace std;

struct Node {
	int val;
	Node *next, *prev;
	Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class MyLinkedList {
	Node *head, *tail;
	int size;

public:
	MyLinkedList() {
		size = 0;
		head = tail = nullptr;
	}

	int get(int index) {
		if (index < 0 || index >= size) {
			return -1;
		}
		if (index <= size / 2) {
			Node *node = head;
			while (index-->0) {
				node = node->next;
			}
			return node->val;
		}
		else {
			Node *node = tail;
			while (index++ < size - 1) {
				node = node->prev;
			}
			return node->val;
		}
	}

	void addAtHead(int val) {
		Node *node = new Node(val);
		if (size == 0) {
			head = tail = node;
		}
		else {
			node->next = head;
			head->prev = node;
			head = node;
		}
		++size;
	}

	void addAtTail(int val) {
		Node *node = new Node(val);
		if (size == 0) {
			head = tail = node;
		}
		else {
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
		++size;
	}

	void addAtIndex(int index, int val) {
		if (index <= 0) {
			addAtHead(val);
		}
		else if (index == size) {
			addAtTail(val);
		}
		else if (index > size) {
			return;
		}
		else {
			Node *newNode = new Node(val);
			if (index <= size / 2) {
				Node *node = head;
				while (index-->1) {
					node = node->next;
				}
				newNode->prev = node;
				newNode->next = node->next;
				node->next->prev = newNode;
				node->next = newNode;
			}
			else {
				Node *node = tail;
				while (index++ < size - 1) {
					node = node->prev;
				}
				newNode->next = node;
				newNode->prev = node->prev;
				node->prev->next = newNode;
				node->prev = newNode;
			}
			++size;
		}
	}

	void deleteAtIndex(int index) {
		if (index < 0 || index >= size) {
			return;
		}
		if (size == 1) {
			head = tail = nullptr;
		} else if (index == 0) {
			head = head->next;
		}
		else if (index == size - 1) {
			tail = tail->prev;
		}
		else {
			if (index <= size / 2) {
				Node *node = head;
				while (index-->1) {
					node = node->next;
				}
				node->next = node->next->next;
				node->next->prev = node;
			}
			else {
				Node *node = tail;
				while (index++ < size - 2) {
					node = node->prev;
				}
				node->prev = node->prev->prev;
				node->prev->next = node;
			}
		}
		--size;
	}
};

int main(void){
	MyLinkedList linkedList = MyLinkedList();
	linkedList.addAtHead(1);
	linkedList.addAtTail(3);
	linkedList.addAtIndex(1, 2);   //链表变为1-> 2-> 3
	cout << linkedList.get(1) << endl;            //返回2
	linkedList.deleteAtIndex(1);  //现在链表是1-> 3
	cout << linkedList.get(1) << endl;            //返回3
}
