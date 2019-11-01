#include <stdio.h>
int n, k;
const int MAX = 100010;
bool check[MAX];
int cnt = 0;

void dfs(int x) {
	check[x] = true;
	cnt++;


	if (x * 2 <= n && check[x * 2] == false)
		dfs(x * 2);
	if (x / 3 > 0 && check[x / 3] == false)
		dfs(x / 3);
}



int main() {

	//Please Enter Your Code Here
	scanf("%d %d", &n, &k);

	dfs(k);
	printf("%d", n - cnt);
	return 0;
}