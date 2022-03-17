#include <iostream>
#include <vector>

using namespace std;

class Bank {
	vector<long long> balance;
public:
	Bank(vector<long long>& balance) : balance(balance){}

	bool transfer(int account1, int account2, long long money) {
		if (account1 <= balance.size() && account2 <= balance.size() && balance[account1 - 1] >= money) {
			balance[account1 - 1] -= money;
			balance[account2 - 1] += money;
			return true;
		}
		else {
			return false;
		}
	}

	bool deposit(int account, long long money) {
		if (account <= balance.size()) {
			balance[account - 1] += money;
			return true;
		}
		else {
			return false;
		}
	}

	bool withdraw(int account, long long money) {
		if (account <= balance.size() && balance[account - 1] >= money) {
			balance[account - 1] -= money;
			return true;
		}
		else {
			return false;
		}
	}
};

int main(void){
	Bank bank = Bank(vector<long long> { 10, 100, 20, 50, 30 });
	cout << bank.withdraw(3, 10) << endl;     // 返回 true ，账户 3 的余额是 $20，所以可以取款 $10 。账户 3 余额为 $20 - $10 = $10 。
	cout << bank.transfer(5, 1, 20) << endl; // 返回 true ，账户 5 的余额是 $30，所以可以转账 $20 。账户 5 的余额为 $30 - $20 = $10 ，账户 1 的余额为 $10 + $20 = $30 。
	cout << bank.deposit(5, 20) << endl;     // 返回 true ，可以向账户 5 存款 $20。账户 5 的余额为 $10 + $20 = $30 。
	cout << bank.transfer(3, 4, 15) << endl;  // 返回 false ，账户 3 的当前余额是 $10。所以无法转账 $15 。
	cout << bank.withdraw(10, 50) << endl;    // 返回 false ，交易无效，因为账户 10 并不存在。
}
