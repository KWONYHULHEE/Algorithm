#include <cstdio>
#include <vector>
using namespace std;

int n, m;
const int MAX = 110;
vector <int> arr[MAX];
vector <int> reversearr[MAX];
bool check[MAX];
bool check2[MAX];
int cnt1 = 0; int cnt2 = 0;
void init() {

	for (int i = 1; i <= n; i++) {
		check[i] = false;
		check2[i] = false;
	}
	cnt1 = 0;
	cnt2 = 0;
}
void dfs1(int x) {
	check[x] = true;
	cnt1++;

	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];
		if (check[y] == false)
			dfs1(y);
	}
}
void dfs2(int x) {
	check2[x] = true;
	cnt2++;

	for (int i = 0; i < reversearr[x].size(); i++) {
		int y = reversearr[x][i];
		if (check2[y] == false)
			dfs2(y);
	}
}
int main() {
	int res = 0;
	scanf("%d %d", &n, &m);
	int mid = (n + 1) / 2;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a].push_back(b);
		reversearr[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {

		dfs1(i);
		dfs2(i);

		if (cnt1 > mid || cnt2 > mid)
			res++;

		init();

	}



	printf("%d", res);

	return 0;
}