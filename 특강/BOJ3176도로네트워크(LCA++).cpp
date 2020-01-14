#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/*

LCA

ac[x][i] = ac[ac[x][i-1]][i-1]
ac[x][i]�� x�� 2^i��° ������ �ǹ�
make_tree : ó�� ���� ����,  dp�����
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
	dp[a][0] = parent; // a�� 1��° ���� = parent

	maxdp[a][0] = val; //a�� 1��° ��������� maxdp
	mindp[a][0] = val;


	for (int i = 1; i < 17; i++) {  // 17 = (int)floor(log2(MAX))
		dp[a][i] = dp[dp[a][i - 1]][i - 1]; //2^i = 2^(i-1)+2^(i-1)
		mindp[a][i] = min(mindp[a][i - 1], mindp[dp[a][i - 1]][i - 1]);
		maxdp[a][i] = max(maxdp[a][i - 1], maxdp[dp[a][i - 1]][i - 1]);
		// minDP[a][i]�� a�� i-1������ minDP���� dp[a][i - 1]][i - 1]�� �� �ּڰ��� ������.
	}

	for (int i = 0; i < v[a].size(); i++) {
		//����� �׷������� �ܹ��� �׷��� ��, Ʈ���� ����
		if (v[a][i].first != parent) {  //a�� ������ ���� �ȵ������� 
			make_tree(v[a][i].first, a, v[a][i].second);  //�������ش�
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
	make_tree(1, 0, 0);  //��Ʈ���� 1 ��Ʈ����� �θ�� 0���� �ʱ�ȭ�Ǿ���
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

		//���� ������ ���ϱ� ������� �ö����� (��Ʈ����) �� �Ÿ��� �������

		if (a != lca) 
		{
			resmax = max(resmax, max(maxdp[a][0], maxdp[b][0]));
			resmin = min(resmin, min(mindp[a][0], mindp[b][0]));
		}

		

		printf("%d %d\n", resmin, resmax);
	}



	return 0;
}