#include <iostream>
#include <vector>
using namespace std;

class StockSpanner {
	vector<int> prices;
	vector<int> days;
public:
	StockSpanner() {}

	int next(int price) {
		int res = 1;
		while (!prices.empty() && prices.back() <= price) {
			res += days.back();
			prices.pop_back();
			days.pop_back();
		}
		prices.emplace_back(price);
		days.emplace_back(res);
		return res;
	}
};

int main(void){
	StockSpanner* obj = new StockSpanner();
	cout << obj->next(100) << endl;
	cout << obj->next(80) << endl;
	cout << obj->next(60) << endl;
	cout << obj->next(70) << endl;
	cout << obj->next(60) << endl;
	cout << obj->next(75) << endl;
	cout << obj->next(85) << endl;
}
