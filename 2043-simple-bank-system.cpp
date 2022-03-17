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
	cout << bank.withdraw(3, 10) << endl;     // ���� true ���˻� 3 ������� $20�����Կ���ȡ�� $10 ���˻� 3 ���Ϊ $20 - $10 = $10 ��
	cout << bank.transfer(5, 1, 20) << endl; // ���� true ���˻� 5 ������� $30�����Կ���ת�� $20 ���˻� 5 �����Ϊ $30 - $20 = $10 ���˻� 1 �����Ϊ $10 + $20 = $30 ��
	cout << bank.deposit(5, 20) << endl;     // ���� true ���������˻� 5 ��� $20���˻� 5 �����Ϊ $10 + $20 = $30 ��
	cout << bank.transfer(3, 4, 15) << endl;  // ���� false ���˻� 3 �ĵ�ǰ����� $10�������޷�ת�� $15 ��
	cout << bank.withdraw(10, 50) << endl;    // ���� false ��������Ч����Ϊ�˻� 10 �������ڡ�
}
