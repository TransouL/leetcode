#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;
#define max(a,b) ((a) > (b) ? (a) : (b))

class StockPrice {
	unordered_map<int, int> timePrices;
	int latestTime;
	multiset<int> prices;

public:
	StockPrice() {
		this->latestTime = 0;
	}

	void update(int timestamp, int price) {
		latestTime = max(latestTime, timestamp);
		int prevPrice = timePrices.count(timestamp) ? timePrices[timestamp] : 0;
		timePrices[timestamp] = price;
		if (prevPrice > 0) {
			auto it = prices.find(prevPrice);
			prices.erase(it);
		}
		prices.emplace(price);
	}

	int current() {
		return timePrices[latestTime];
	}

	int maximum() {
		return *prices.rbegin();
	}

	int minimum() {
		return *prices.begin();
	}
};

int main(void){
	StockPrice stockPrice = StockPrice();
	stockPrice.update(1, 10); // 时间戳为 [1] ，对应的股票价格为 [10] 。
	stockPrice.update(2, 5);  // 时间戳为 [1,2] ，对应的股票价格为 [10,5] 。
	cout << stockPrice.current() << endl;     // 返回 5 ，最新时间戳为 2 ，对应价格为 5 。
	cout << stockPrice.maximum() << endl;     // 返回 10 ，最高价格的时间戳为 1 ，价格为 10 。
	stockPrice.update(1, 3);  // 之前时间戳为 1 的价格错误，价格更新为 3 。 
								// 时间戳为 [1,2] ，对应股票价格为 [3,5] 。
	cout << stockPrice.maximum() << endl;     // 返回 5 ，更正后最高价格为 5 。
	stockPrice.update(4, 2);  // 时间戳为 [1,2,4] ，对应价格为 [3,5,2] 。
	cout << stockPrice.minimum() << endl;     // 返回 2 ，最低价格时间戳为 4 ，价格为 2 。
}
