#include <iostream>
using namespace std;

int n;
int arr[1010];

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	
	int ans = 0;
	int temp = 0;
	for (int i = 0; i < n; i++) {
		temp += arr[i];
		ans += temp;
	}

	cout << ans;
	return 0;
}