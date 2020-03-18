#include <iostream>
#include <queue>
using namespace std;

int n;


void bfs() {
	bool check[1010][1010] = { 0, };
	queue <pair<pair<int, int>, int>> q;
	q.push({{ 1,0 }, 0});
	check[1][0] = true;

	while (!q.empty()) {
		int dis = q.front().first.first;
		int clip = q.front().first.second;
		int time = q.front().second;
		q.pop();

		if (dis == n) {
			cout << time << "\n";
			return;
		}

		if (dis <= 1000 && !check[dis][dis]) {
			check[dis][dis] = true;
			q.push({ {dis,dis},time + 1 });
		}

		if (dis + clip <= 1000 && !check[dis + clip][clip]) {
			check[dis + clip][clip] = true;
			q.push({ { dis + clip,clip }, time + 1 });
		}

		if (dis - 1 >= 1 && !check[dis - 1][clip]) {
			check[dis - 1][clip] = true;
			q.push({ { dis - 1,clip }, time + 1 });
		}
		
	}


}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	bfs();

	return 0;
}