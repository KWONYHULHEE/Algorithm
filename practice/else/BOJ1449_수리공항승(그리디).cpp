#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[1010];

int main() {

	int n, l;
	cin >> n >> l;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	int tape = arr[0];
	int temp = tape + l - 1;
	for (int i = 0; i < n; i++) {
		if (temp < arr[i]) {
			cnt++;
			tape = arr[i];
			temp = tape + l - 1;
		}
	}
	cout << cnt;
	return 0;
}