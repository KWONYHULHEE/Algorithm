#include <iostream>
#include <algorithm>

using namespace std;
int M, N, ans = 2e9 + 1;
int arr[100001];

int findAns() {
	int s = 0, e = 1;

	while (s < N) {

		if (arr[e] - arr[s] < M) {
			e++;
		}
		else {
			ans = min(ans, arr[e] - arr[s]);
			s++;
		}
	}

	return ans;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin>>arr[i];
	}
	sort(arr, arr + N);
	cout<<findAns();
	return 0;
}