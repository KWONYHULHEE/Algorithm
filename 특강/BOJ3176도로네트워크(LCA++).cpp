#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/*

LCA

ac[x][i] = ac[ac[x][i-1]][i-1]
ac[x][i]는 x의 2^i번째 조상을 의미
make_tree : 처음 깊이 설정,  dp만들기
*/


const int MAX = 100010;

int n, m;
int depth[MAX];
int dp[MAX][20];
int maxdp[MAX][20];
int mindp[MAX][20];

vector<pair<int, int>> v[MAX];

void make_tree(int a, int parent,int val) {

	depth[a] = depth[parent] + 1;
	dp[a][0] = parent; // a의 1번째 조상 = parent

	maxdp[a][0] = val; //a의 1번째 조상까지의 maxdp
	mindp[a][0] = val;


	for (int i = 1; i < 17; i++) {  // 17 = (int)floor(log2(MAX))
		dp[a][i] = dp[dp[a][i - 1]][i - 1]; //2^i = 2^(i-1)+2^(i-1)
		mindp[a][i] = min(mindp[a][i - 1], mindp[dp[a][i - 1]][i - 1]);
		maxdp[a][i] = max(maxdp[a][i - 1], maxdp[dp[a][i - 1]][i - 1]);
		// minDP[a][i]는 a의 i-1까지의 minDP값과 dp[a][i - 1]][i - 1]값 중 최솟값을 가진다.
	}

	for (int i = 0; i < v[a].size(); i++) {
		//양방향 그래프에서 단방향 그래프 즉, 트리로 생성
		if (v[a][i].first != parent) {  //a의 조상이 설정 안되있으면 
			make_tree(v[a][i].first, a, v[a][i].second);  //설정해준다
		}
	}
}


int main() {

	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));

	}
	depth[0] = -1;
	make_tree(1, 0, 0);  //루트노드는 1 루트노드의 부모는 0으로 초기화되야함
	//make_DP();

	scanf("%d", &m);

	while (m--) {

		int a, b;
		int resmax = -1;
		int resmin = 987654321;
		scanf("%d %d", &a, &b);

		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b]) swap(a, b);
			for (int i = 16; i >= 0; i--) {
				if (depth[a] <= depth[dp[b][i]]) {
					resmax = max(resmax, maxdp[b][i]);
					resmin = min(resmin, mindp[b][i]);

					b = dp[b][i];

				}
			}
		}

		int lca = a;

		if (a != b) {
			for (int i = 16; i >= 0; i--) {
				if (dp[a][i] != dp[b][i]) {

					resmax = max(resmax, max(maxdp[a][i], maxdp[b][i]));
					resmin = min(resmin, min(mindp[a][i], mindp[b][i]));

					a = dp[a][i];
					b = dp[b][i];
				}
				lca = dp[a][i];
				/*
				resmax = max(resmax, max(maxdp[a][0], maxdp[b][0]));
				resmin = min(resmin, min(mindp[a][0], mindp[b][0]));
				*/
			}
		}

		//조상 전까지 가니까 조상까지 올라갔을때 (루트까지) 의 거리도 재줘야함

		if (a != lca) 
		{
			resmax = max(resmax, max(maxdp[a][0], maxdp[b][0]));
			resmin = min(resmin, min(mindp[a][0], mindp[b][0]));
		}

		

		printf("%d %d\n", resmin, resmax);
	}



	return 0;
}