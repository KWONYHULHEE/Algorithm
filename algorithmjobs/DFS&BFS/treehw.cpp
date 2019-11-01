#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 1010;
int n;
int order[MAX];
int depth[MAX];
bool check[MAX];
vector <int> arr[MAX];
struct Tree {
	int left;
	int right;
};
Tree tree[MAX];
int k = 1;
void inorder(int x) {
	if (tree[x].left == -1 && tree[x].right == -1)
		order[x] = k++;
	else {

		if (tree[x].left != -1)
			inorder(tree[x].left);

		order[x] = k++;

		if (tree[x].right != -1)
			inorder(tree[x].right);
	}



}
void dfs(int x, int dep) {
	check[x] = true;
	depth[x] = dep;

	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];

		if (check[y] == false)
			dfs(y, dep + 1);
	}
}
int main() {

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		tree[a].left = b;
		tree[a].right = c;
		if (b != -1) {
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		if (c != -1) {
			arr[a].push_back(c);
			arr[c].push_back(a);
		}
	}
	inorder(1);
	dfs(1, 1);
	int t = 1; int max = -1; int res = 0; int level = 0;

	for (int i = 1; i <= n; i++) {

		if (depth[i] != depth[i + 1]) {
			res = order[i] - order[t] + 1;
			t = i + 1;
		}


		if (res > max) {
			max = res;
			level = t - 1;
		}

	}
	printf("%d %d", depth[level], max);

	return 0;
}