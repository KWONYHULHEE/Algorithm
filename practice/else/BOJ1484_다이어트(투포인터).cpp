#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);

	int g;
	cin >> g;
	long long e = 1, s = 1;
	bool existed = false;

	while (1) {
		if (e * e - s * s == g) {
			existed = true;
			cout << e << "\n";
		}
		if (e - s == 1 && e * e - s * s > g) break;
		if (e * e - s * s > g) s++;
		else e++;
	}
	if (!existed) cout << -1;

	return 0;
}
