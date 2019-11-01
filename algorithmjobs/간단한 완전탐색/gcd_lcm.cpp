#include <iostream>
using namespace std;

int main() {

	//Please Enter Your Code Here

	int a, b;
	cin >> a >> b;

	int A = a;
	int B = b;
	int gcd = 0;
	int lcm = 0;
	while (1) {

		int r = a % b;

		if (r == 0) {
			gcd = b;
			break;
		}
		a = b;
		b = r;

	}

	lcm = (A*B) / gcd;

	cout << gcd << endl << lcm;



	return 0;
}