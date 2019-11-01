#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 100010;
int n;
vector <int> arr[MAX];
vector <int> reversearr[MAX];
int order[MAX];
int order_len = 0;
bool check[MAX];
bool check2[MAX];
int group[MAX];
int group_cnt = 1;

void gettime(int x) {
	check[x] = true;

	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];

		if (check[y] == false) {
			gettime(y);
		}
	}
	order[order_len++] = x;

}
void find_group(int x) {
	check2[x] = true;
	group[x] = group_cnt;

	for (int i = 0; i < reversearr[x].size(); i++) {
		int y = reversearr[x][i];

		if (check2[y] == false) {
			find_group(y);
		}
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
			gettime(i);
		}
	}

	for (int i = order_len - 1; i >= 0; i--) {
		int node = order[i];
		if (!check2[node]) {
			find_group(node);
			group_cnt++;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (group[i] != group[arr[i][0]])
			cnt++;
	}

	printf("%d", cnt);
	return 0;
}


