#include <iostream>
#include <algorithm>
using namespace std;


int main() {

	int r, b;

	cin >> r >> b;
	int sum = r + b;
	int l = 0;
	int w = 0;
	for (int i = 1; i <= b; i++) {
		if (b%i == 0) {
			if ((i + 2)*((b / i) + 2) == sum) {
				l = max((i + 2), (b / i) + 2);
				w = min((i + 2), (b / i) + 2);
				break;
			}

		}
	}
	cout << l << " " << w << "\n";
}