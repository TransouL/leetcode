#include <iostream>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

class FreqStack {
	unordered_map<int, int> freq;
	unordered_map<int, stack<int>> group;
	int maxFreq;

public:
	FreqStack() {
		maxFreq = 0;
	}

	void push(int val) {
		freq[val]++;
		group[freq[val]].push(val);
		maxFreq = max(maxFreq, freq[val]);
	}

	int pop() {
		int val = group[maxFreq].top();
		freq[val]--;
		group[maxFreq].pop();
		if (group[maxFreq].empty()) {
			maxFreq--;
		}
		return val;
	}
};

int main(void){
	FreqStack *obj = new FreqStack();
	obj->push(5);
	obj->push(7);
	obj->push(5);
	obj->push(7);
	obj->push(4);
	obj->push(5);
	cout << obj->pop() << endl;
	cout << obj->pop() << endl;
	cout << obj->pop() << endl;
	cout << obj->pop() << endl;
}
