#include <stdio.h>
int n;
int arr[100010];

bool result(int len) {

	int cnt[100010] = { 0, };
	int x = 0;
	int y = 0;

	for (int i = 0; i < len; i++) {
		cnt[arr[i]]++;
	}

	for (int i = 1; i <= n; i++) {
		if (cnt[i] >= 2)
			x++;
	}

	if (x == 0)
		return true;

	while (len + y < n) {

		cnt[arr[y]]--;
		if (cnt[arr[y]] == 1)
			x--;
		y++;
		cnt[arr[y + len - 1]]++;
		if (cnt[arr[y + len - 1]] == 2)
			x++;

		if (x == 0) return true;

	}
	return false;
}



int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	if (result(n))
	{
		printf("%d", n);
		return 0;
	}

	int s = 1;
	int e = n;
	int mid = 0;

	while (s + 1 < e) {
		mid = (s + e) / 2;
		if (!result(mid)) e = mid;
		else s = mid;
	}

	printf("%d", s);
	return 0;
}