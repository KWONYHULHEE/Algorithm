#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
/*

LCA 

ac[x][i] = ac[ac[x][i-1]][i-1]
ac[x][i]�� x�� 2^i��° ������ �ǹ�

ac[ac[x][i-1]][i-1]�� ���� Ǯ��� x�� 2^(i-1)��° ������ 2^(i-1)��° �����̴�.
��, x�� 2^(i-1)+2^(i-1)��° �����̶�� ���̱� ������ x�� 2^i��° �����̶�� ���� ����. 
�̷������� ��Ʈ���κ��� ���������� DFS�� Ž���ϸ� �� ��ȭ�Ĵ�� ������ �Ǹ� 
��� ��� x�� ���Ͽ� 2^i��° ������ ���� �� �ִ�.


make_tree : ó�� ���� ����,  dp�����
*/

const int MAX = 100010;

vector <int> arr[MAX];
int depth[MAX];
int dp[MAX][20];


void make_tree(int a, int parent) {

	depth[a] = depth[parent] + 1;
	dp[a][0] = parent; // a�� 1��° ���� = parent
	
	for (int i = 1; i < 17; i++) {  // 17 = (int)floor(log2(MAX))
		dp[a][i] = dp[dp[a][i - 1]][i - 1]; //2^i = 2^(i-1)+2^(i-1)
	}

	for (int i = 0; i < arr[a].size(); i++) {   
		//����� �׷������� �ܹ��� �׷��� ��, Ʈ���� ����
		if (arr[a][i] != parent) {  //a�� ������ ���� �ȵ������� 
			make_tree(arr[a][i], a);  //�������ش�
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
	make_tree(1, 0);  //��Ʈ���� 1 ��Ʈ����� �θ�� 0���� �ʱ�ȭ�Ǿ���


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