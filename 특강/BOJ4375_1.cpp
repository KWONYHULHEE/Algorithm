#include <iostream>
#include<math.h>
using namespace std;

/*

(이전 값 * 10 + 1)%n
= 현재값 % n

*/
int main() {
	int n;

	while (cin >> n) {
		int num=0;
		for (int i = 1;; i++) {
			num =num*10+1;
			num = num % n;
			if (num == 0) {
				cout << i <<'\n';
				break;
			}
		}
	}
}
