#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/*

LCA 

ac[x][i] = ac[ac[x][i-1]][i-1]
ac[x][i]는 x의 2^i번째 조상을 의미

ac[ac[x][i-1]][i-1]를 말로 풀어쓰면 x의 2^(i-1)번째 조상의 2^(i-1)번째 조상이다.
즉, x의 2^(i-1)+2^(i-1)번째 조상이라는 말이기 때문에 x의 2^i번째 조상이라는 말과 같다. 
이런식으로 루트노드로부터 리프노드까지 DFS로 탐색하며 위 점화식대로 돌리게 되면 
모든 노드 x에 대하여 2^i번째 조상을 구할 수 있다.


make_tree : 처음 깊이 설정,  dp만들기
*/

const int MAX = 100010;

vector <int> arr[MAX];
int depth[MAX];
int dp[MAX][20];


void make_tree(int a, int parent) {

	depth[a] = depth[parent] + 1;
	dp[a][0] = parent; // a의 1번째 조상 = parent
	
	for (int i = 1; i < 17; i++) {  // 17 = (int)floor(log2(MAX))
		dp[a][i] = dp[dp[a][i - 1]][i - 1]; //2^i = 2^(i-1)+2^(i-1)
	}

	for (int i = 0; i < arr[a].size(); i++) {   
		//양방향 그래프에서 단방향 그래프 즉, 트리로 생성
		if (arr[a][i] != parent) {  //a의 조상이 설정 안되있으면 
			make_tree(arr[a][i], a);  //설정해준다
		}
	}

}

int main() {

	int n, m;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	depth[0] = -1;
	make_tree(1, 0);  //루트노드는 1 루트노드의 부모는 0으로 초기화되야함


	scanf("%d", &m);
	while (m--) {

		int a, b;
		scanf("%d %d", &a, &b);

		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b]) swap(a, b);
			for (int i = 16; i >= 0; i--) {
				if (depth[a] <= depth[dp[b][i]]) {
					b = dp[b][i];
				}
			}
		}

		int res = a;

		if (a != b) {
			for (int i = 16; i >= 0; i--) {
				if (dp[a][i] != dp[b][i]) {
					a = dp[a][i];
					b = dp[b][i];
				}
				res = dp[a][i];
			}
		}

		printf("%d\n", res);
	}



	return 0;
}