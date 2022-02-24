#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string complexNumberMultiply(string num1, string num2) {
		int divide1 = num1.find('+'), n1 = num1.size(), divide2 = num2.find('+'), n2 = num2.size();
		int real1 = stoi(num1.substr(0, divide1)), imaginary1 = stoi(num1.substr(divide1 + 1, n1 - 1)), real2 = stoi(num2.substr(0, divide2)), imaginary2 = stoi(num2.substr(divide2 + 1, n2 - 1));
		return to_string(real1 * real2 - imaginary1 * imaginary2) + "+" + to_string(real1 * imaginary2 + real2 * imaginary1) + "i";
	}
};

int main(void){
	Solution solution = Solution();
	cout << solution.complexNumberMultiply("1+1i", "1+1i") << endl;
	cout << solution.complexNumberMultiply("1+-1i", "1+-1i") << endl;
	cout << solution.complexNumberMultiply("78+-76i", "-86+72i") << endl; // "-1236+12152i"
}
