#include <stdio.h>
#include <vector>
using namespace std;

bool check[110];
int n, r;
vector <int> arr[110];
int qqq = -1;

void tree(int x, int height) {

	check[x] = true;
	if (qqq < height) {
		qqq = height;

	}

	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];
		if (check[y] == false) {
			tree(y, height + 1);
		}
	}


}


int main() {

	//Please Enter Your Code Here
	scanf("%d %d", &n, &r);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);


		arr[a].push_back(b);
		arr[b].push_back(a);

	}
	tree(r, 0);

	printf("%d", qqq);

	return 0;
}