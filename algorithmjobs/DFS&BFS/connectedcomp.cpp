#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 1010;
int v, e;
vector <int> arr[MAX];
bool check[MAX];
void dfs(int x) {
	check[x] = true;

	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];

		if (check[y] == false) {
			dfs(y);
		}
	}

}
int main() {

	scanf("%d %d", &v, &e);

	for (int i = 0; i < e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		arr[a].push_back(b);
		arr[b].push_back(a);

	}
	int cnt = 0;

	for (int i = 1; i <= v; i++) {
		if (!check[i]) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d", cnt);

	return 0;
}