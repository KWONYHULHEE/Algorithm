#include <cstdio>
#include <vector>
using namespace std;

/*

 간선의 정방향, 역방향 에dfs 돌렸을때
 모두와 이어져 있으면 순서를 알수있는 정점임.
*/
bool check1[510];
bool check2[510];

vector <int> v1[510];
vector <int> v2[510];

int cnt1 = -1;
int cnt2 = -1;

void init() {
	for (int i = 0; i < 510; i++) {
		check1[i] = false;
		check2[i] = false;
	}
}

int dfs1(int x) {

	
	check1[x] = true;
	cnt1++;

	for (int i = 0; i < v1[x].size(); i++) {
		int next = v1[x][i];
		if (!check1[next]) {
			dfs1(next);
		}
	}

	return cnt1;

}

int dfs2(int x) {

	
	check2[x] = true;
	cnt2++;

	for (int i = 0; i < v2[x].size(); i++) {
		int next = v2[x][i];
		if (!check2[next]) {
			dfs2(next);
		}
	}
	return cnt2;
}

int main() {

	int n, m;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v1[a].push_back(b);
		v2[b].push_back(a);

	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		cnt1 = -1;
		cnt2 = -1;
		init();
		if (dfs1(i) + dfs2(i) == n - 1) res++;
	}
	


	printf("%d", res);

	return 0;
}