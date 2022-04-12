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
	cout << randomizedSet.insert(1) << endl; // 向集合中插入 1 。返回 true 表示 1 被成功地插入。
	cout << randomizedSet.remove(2) << endl; // 返回 false ，表示集合中不存在 2 。
	cout << randomizedSet.insert(2) << endl; // 向集合中插入 2 。返回 true 。集合现在包含 [1,2] 。
	cout << randomizedSet.getRandom() << endl; // getRandom 应随机返回 1 或 2 。
	cout << randomizedSet.remove(1) << endl; // 从集合中移除 1 ，返回 true 。集合现在包含 [2] 。
	cout << randomizedSet.insert(2) << endl; // 2 已在集合中，所以返回 false 。
	cout << randomizedSet.getRandom() << endl; // 由于 2 是集合中唯一的数字，getRandom 总是返回 2 。
}
