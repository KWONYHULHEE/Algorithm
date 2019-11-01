#include <stdio.h>
#include <queue>
using namespace std;

int n;
const int MAX = 100010;
int cnt = 0;

void bfs(int x) {

	queue <int> q;
	bool check[MAX] = { 0, };
	q.push(x);
	check[x] = true;


	while (!q.empty()) {
		int size = q.size();
		cnt++;

		while (size--) {
			int current = q.front();
			q.pop();

			if (current == n) return;

			if (current * 2 < 100000 && check[current * 2] == false) {
				check[current * 2] = true;
				q.push(current * 2);
			}
			if (current / 3 > 0 && check[current / 3] == false) {
				check[current / 3] = true;
				q.push(current / 3);
			}

		}
	}

}
int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);
	bfs(1);
	printf("%d", cnt - 1);

	return 0;
}