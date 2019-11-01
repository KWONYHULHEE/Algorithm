#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

char arr[300];
int str[300];
int n, k;
char change[300];
bool desc(int a, int b) {
	return a > b;
}
void init() {
	int i;

	for (i = 0; i < 10; i++)
		change[i + '0'] = i;
	for (i = 0; i < 6; i++)
		change[i + 'A'] = i + 10;
}
void rotate() {

	int temp = str[n - 1];

	for (int i = n - 1; i > 0; i--) {
		str[i] = str[i - 1];
	}
	str[0] = temp;
}
int solve() {


	vector <int> pw;

	for (int p = 0; p < n / 4; p++) {
		int s = 0;

		for (int j = 0; j < 4; j++) {
			int len = n / 4;
			int mul = 1;
			int sum = 0;

			for (int i = s + len - 1; i >= s; i--) {
				sum += mul * str[i];
				mul *= 16;
			}

			pw.push_back(sum);
			s += len;
		}
		rotate();
	}

	sort(pw.begin(), pw.end(), desc);
	int size = pw.size();
	int order = 0;
	int before = -1;
	int i = 0;

	for (i = 0; i < size; i++) {
		if (before != pw[i]) {
			before = pw[i];
			order++;
		}

		if (order == k)
			break;

	}
	return pw[i];
}
int main() {


	int tc;
	init();
	scanf("%d", &tc);

	for (int t = 1; t <= tc; t++) {
		scanf("%d %d", &n, &k);

		scanf("%s", arr);

		for (int i = 0; i < n; i++) {
			str[i] = change[arr[i]];
		}

		printf("#%d %d\n", t, solve());

	}

	return 0;
}