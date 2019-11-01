#include <stdio.h>
#include <queue>
using namespace std;

int t;
const int MAX = 10000;
int prime[MAX];
int cnt = 0;
bool flag = false;

int changenum(int current, int pos, int num) {
	int k = current;

	if (pos == 1) {
		k -= (current / 1000) * 1000;
		k += num * 1000;
	}
	else if (pos == 2) {
		k -= ((current % 1000) / 100) * 100;
		k += num * 100;
	}
	else if (pos == 3) {
		k -= (((current % 1000) % 100) / 10) * 10;
		k += num * 10;
	}
	else if (pos == 4) {
		k -= (((current % 1000) % 100) % 10);
		k += num;
	}

	return k;

}



void bfs(int s, int e) {
	bool check[MAX] = { 0, };
	queue <int> q;
	check[s] = true;
	q.push(s);

	while (!q.empty()) {
		int size = q.size();
		cnt++;
		while (size--) {
			int current = q.front();
			q.pop();

			if (current == e) {
				flag = true;
				return;
			}


			for (int i = 1; i <= 4; i++) {
				for (int j = 0; j <= 9; j++) {
					int next = changenum(current, i, j);


					if (next < 1000 || prime[next] == 0) continue;
					if (check[next] == false) {
						check[next] = true;

						q.push(next);
					}
				}
			}

		}
	}


}



int main() {

	for (int i = 1001; i < 10000; i++) {
		prime[i] = 1;
		for (int j = 2; j < i; j++) {
			if (i%j == 0) {
				prime[i] = 0;
				break;
			}
		}
	}

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		bfs(a, b);

		if (flag == true) printf("%d\n", cnt - 1);
		else printf("impossible");

		cnt = 0;
		flag = false;

	}


	return 0;
}