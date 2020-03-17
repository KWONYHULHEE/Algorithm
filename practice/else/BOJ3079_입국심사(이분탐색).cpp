#include <iostream>
#include <algorithm>
using namespace std;

long long arr[100010];

int main() {
	int n, m;
	cin >> n >> m;
	long long maxvalue = -1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		maxvalue = max(maxvalue, arr[i]);
	}

	long long start = 1;
	long long end = maxvalue * m;
	long long result = end;

	while (start <= end) {
		long long mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sum += mid / arr[i];
		}

		if (sum < m) {
			start = mid + 1;
		}
		else { // 같거나 클때가 이미 만족한거니까 여기서 확인해조
			if (result > mid) result = mid;
			end = mid - 1;
		}
	}

	cout << result;

	return 0;
}