#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int arr[1010];
int str[1010];
vector <int> ans,temp1,temp2;
int cnt;
int p[1010];


int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	ans.push_back(arr[1]);

	for (int i = 2; i <= n; i++) {
		if (ans[cnt] < arr[i]) {
			ans.push_back(arr[i]), cnt++;
			p[i] = cnt;
		}
		else {
			int pos = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
			ans[pos] = arr[i];
			p[i] = pos;
		}
	}


	for (int i = 1; i <=n ; i++) {
		temp1.push_back(p[i] + 1);
	}


	ans.clear();
	cnt = 0;
	memset(p, 0, sizeof(p));
	
	for (int i = 1; i <= n; i++) {
		str[n - i + 1] = arr[i];
	}

	ans.push_back(str[1]);

	for (int i = 2; i <= n; i++) {
		if (ans[cnt] < str[i]) {
			ans.push_back(str[i]), cnt++;
			p[i] = cnt;
		}
		else {
			int pos = lower_bound(ans.begin(), ans.end(), str[i]) - ans.begin();
			ans[pos] = str[i];
			p[i] = pos;
		}
	}

	for (int i = 1; i <= n; i++) {
		temp2.push_back(p[i] + 1);
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (temp1[i] + temp2[n-i-1] > res) res = temp1[i] + temp2[n - i - 1];
	}

	cout << res - 1;
}