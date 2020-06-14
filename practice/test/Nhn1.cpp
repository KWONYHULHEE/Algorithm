#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string input;


int main() {
	
	string input;
	cin >> input;
	
	for (int i = 0; i < input.size(); i+=16) {
		for (int j = i; j < i + 16; j+=4) {
			int temp = 8;
			int sum = 0;
			for (int k = j; k < j + 4; k++) {
				int num = input[k] - '0';
				num *= temp;
				sum += num;
				temp /= 2;
			}
			if (sum < 10) cout << sum;
			else {
				if (sum == 10) cout << "a";
				if (sum == 11) cout << "b";
				if (sum == 12) cout << "c";
				if (sum == 13) cout << "d";
				if (sum == 14) cout << "e";
				if (sum == 15) cout << "f";
			}
		}
		if(i!=input.size()-16) cout << ":";
	}

	return 0;
}