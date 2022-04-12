#include <iostream>
#include <vector>
#include <unordered_map>
#include <time.h>
using namespace std;

class RandomizedSet {
private:
	vector<int> nums;
	unordered_map<int, int> indices;

public:
	RandomizedSet() {
		srand((unsigned)time(NULL));
	}

	bool insert(int val) {
		if (indices.count(val)) {
			return false;
		}
		int index = nums.size();
		nums.emplace_back(val);
		indices.emplace(val, index);
		return true;
	}

	bool remove(int val) {
		if (!indices.count(val)) {
			return false;
		}
		int index = indices[val];
		int last = nums.back();
		nums[index] = last;
		indices[last] = index;
		nums.pop_back();
		indices.erase(val);
		return true;
	}

	int getRandom() {
		return nums[rand() % nums.size()];
	}
};

int main(void){
	RandomizedSet randomizedSet = RandomizedSet();
	cout << randomizedSet.insert(1) << endl; // �򼯺��в��� 1 ������ true ��ʾ 1 ���ɹ��ز��롣
	cout << randomizedSet.remove(2) << endl; // ���� false ����ʾ�����в����� 2 ��
	cout << randomizedSet.insert(2) << endl; // �򼯺��в��� 2 ������ true ���������ڰ��� [1,2] ��
	cout << randomizedSet.getRandom() << endl; // getRandom Ӧ������� 1 �� 2 ��
	cout << randomizedSet.remove(1) << endl; // �Ӽ������Ƴ� 1 ������ true ���������ڰ��� [2] ��
	cout << randomizedSet.insert(2) << endl; // 2 ���ڼ����У����Է��� false ��
	cout << randomizedSet.getRandom() << endl; // ���� 2 �Ǽ�����Ψһ�����֣�getRandom ���Ƿ��� 2 ��
}
