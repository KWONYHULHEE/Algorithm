#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int col[30];
int cnt = 0;


bool ispossible(int row) {

	for (int i = 1; i < row; i++) {
		if (col[row] == col[i]) return false;
		if (abs(row - i) == abs(col[row] - col[i])) return false;
	}
	return true;
}


void dfs(int row) {
	if (row - 1 == n)
		cnt++;

	else {
		for (int i = 1; i <= n; i++) {
			col[row] = i;
			if (ispossible(row)) {
				dfs(row + 1);
			}
		}
	}
}

int main() {

	//Please Enter Your Code Here

	scanf("%d", &n);
	dfs(1);
	printf("%d", cnt);

	return 0;
}