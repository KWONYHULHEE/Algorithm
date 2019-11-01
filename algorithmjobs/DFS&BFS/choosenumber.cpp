#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 110;
vector <int> arr[MAX];
vector <int> reversearr[MAX];
int n;
int order[MAX]; int order_len = 0;
int group[MAX]; int group_cnt = 1;
bool check[MAX];
bool check2[MAX];

void get_time(int x) {
	check[x] = true;

	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];
		if (check[y] == false)
			get_time(y);
	}
	order[order_len++] = x;
}

void find_group(int x) {
	group[x] = group_cnt;
	check2[x] = true;

	for (int i = 0; i < reversearr[x].size(); i++) {
		int y = reversearr[x][i];

		if (!check2[y])
			find_group(y);
	}
}
int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		arr[i].push_back(a);
		reversearr[a].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			get_time(i);
		}
	}

	for (int i = order_len - 1; i >= 0; i--) {
		int node = order[i];
		if (!check2[node]) {
			find_group(node);
			group_cnt++;
		}
	}
	int same = 0;
	int what[MAX] = { 0, };
	for (int i = 1; i <= n; i++) {
		if (group[i] == group[arr[i][0]]) {
			same++;
			what[i]++;
		}
	}
	printf("%d\n", same);
	for (int i = 1; i <= n; i++) {
		if (what[i] != 0) {
			printf("%d ", i);
		}
	}

	return 0;
}