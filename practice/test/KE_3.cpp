#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
float arr[10010];
int n, k;

bool ispossible(float mid) {


	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > mid) {
			cnt += (arr[i] / mid);
		}
		else if (arr[i] < mid) {
			return false;
		}
		else cnt++;
	}
	//cout << mid << " " << cnt << "\n";
	if (cnt >= k) return true;
	else return false;
}
int main() {

	cin >> n >> k;
	float minvalue = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (minvalue < arr[i]) minvalue = arr[i];
	}

	float s = 0;
	float e = minvalue;
	float res = 0;

	while (s <= e) {
		float mid = (s + e) / 2;
		//cout << mid << " ";
		if (ispossible(mid)) {
			//   cout << mid << " " << res << "\n";
			if (res < mid) res = mid;
			s = mid + 0.001;
		}
		else e = mid - 0.001;
	}

	printf("%.2f", res);
	return 0;
}