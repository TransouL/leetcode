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
	stockPrice.update(1, 10); // ʱ���Ϊ [1] ����Ӧ�Ĺ�Ʊ�۸�Ϊ [10] ��
	stockPrice.update(2, 5);  // ʱ���Ϊ [1,2] ����Ӧ�Ĺ�Ʊ�۸�Ϊ [10,5] ��
	cout << stockPrice.current() << endl;     // ���� 5 ������ʱ���Ϊ 2 ����Ӧ�۸�Ϊ 5 ��
	cout << stockPrice.maximum() << endl;     // ���� 10 ����߼۸��ʱ���Ϊ 1 ���۸�Ϊ 10 ��
	stockPrice.update(1, 3);  // ֮ǰʱ���Ϊ 1 �ļ۸���󣬼۸����Ϊ 3 �� 
								// ʱ���Ϊ [1,2] ����Ӧ��Ʊ�۸�Ϊ [3,5] ��
	cout << stockPrice.maximum() << endl;     // ���� 5 ����������߼۸�Ϊ 5 ��
	stockPrice.update(4, 2);  // ʱ���Ϊ [1,2,4] ����Ӧ�۸�Ϊ [3,5,2] ��
	cout << stockPrice.minimum() << endl;     // ���� 2 ����ͼ۸�ʱ���Ϊ 4 ���۸�Ϊ 2 ��
}
