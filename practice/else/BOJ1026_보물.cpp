#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int a[60];
int b[60];
bool cmp(int x, int y) {
	return x > y;
}
int main() {

	
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n, cmp);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (a[i] * b[i]);
	}

	cout << ans;

	return 0;
}