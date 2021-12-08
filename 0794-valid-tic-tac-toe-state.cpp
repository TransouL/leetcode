#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool validTicTacToe(vector<string>& board) {
		int xcnt = 0, ocnt = 0;
		for (auto &s : board)
			for (auto &ch : s) {
				if (ch == 'X')
					++xcnt;
				if (ch == 'O')
					++ocnt;
			}
		if (xcnt < ocnt || xcnt - ocnt > 1) return false;

		bool xoCntEqual = xcnt == ocnt;
		if (checkConflict(board[0][0], board[0][1], board[0][2], xoCntEqual)
			|| checkConflict(board[1][0], board[1][1], board[1][2], xoCntEqual)
			|| checkConflict(board[2][0], board[2][1], board[2][2], xoCntEqual)
			|| checkConflict(board[0][0], board[1][0], board[2][0], xoCntEqual)
			|| checkConflict(board[0][1], board[1][1], board[2][1], xoCntEqual)
			|| checkConflict(board[0][2], board[1][2], board[2][2], xoCntEqual)
			|| checkConflict(board[0][0], board[1][1], board[2][2], xoCntEqual)
			|| checkConflict(board[0][2], board[1][1], board[2][0], xoCntEqual))
			return false;

		return true;
	}
private:
	bool checkConflict(char &ch1, char &ch2, char &ch3, bool xoCntEqual) {
		if (!xoCntEqual && ch1 == 'O' && ch1 == ch2 && ch1 == ch3) return true;
		if (xoCntEqual && ch1 == 'X' && ch1 == ch2 && ch1 == ch3) return true;
		return false;
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.validTicTacToe(vector<string> {"O  ", "   ", "   "}) << endl;
	cout << solution.validTicTacToe(vector<string> {"XOX", " X ", "   "}) << endl;
	cout << solution.validTicTacToe(vector<string> {"XXX", "   ", "OOO"}) << endl;
	cout << solution.validTicTacToe(vector<string> {"XOX", "O O", "XOX"}) << endl;
	cout << solution.validTicTacToe(vector<string> {"XXX", "OOX", "OOX"}) << endl;
	cout << solution.validTicTacToe(vector<string> {"XXX", "OXO", "OXO"}) << endl;
}