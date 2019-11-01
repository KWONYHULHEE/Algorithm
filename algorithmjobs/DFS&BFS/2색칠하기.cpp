#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 100010;
vector <int> arr[MAX];
bool check[MAX];
int mycolor[MAX];

void dfs(int x) {

	check[x] = true;
	mycolor[0] = 1;

	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];

		if (mycolor[x] != mycolor[y] && mycolor[x] == 1)
			mycolor[y] = -1;
		else if (mycolor[x] != mycolor[y] && mycolor[x] == -1)
			mycolor[y] = 1;
		else
			mycolor[y] = 0;

		if (check[y] == false)
			dfs(y);
	}

}



int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(0);

	for (int i = 0; i < n; i++) {
		if (mycolor[i] == 0) {
			printf("NO");
			return 0;
		}
	}

	printf("YES");

	return 0;
}