#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;


int N, W;
vector<pair<int, int>> v;
int cache[1002][1002];

int dist(int pos1, int pos2) {
	return abs(v[pos1].first - v[pos2].first) + abs(v[pos1].second - v[pos2].second);
}

int mindist(int pos1, int pos2) {
	if (max(pos1, pos2) == W + 1) return 0;

	int& ret = cache[pos1][pos2];
	if (ret!=0) return ret;  // 초기원소가 0이므로 cache값에 계산되어있으면 반환

	ret = 1e9;

	int next = max(pos1, pos2) + 1;
	ret = min(ret, mindist(next, pos2) + dist(pos1, next));
	ret = min(ret, mindist(pos1, next) + dist(pos2, next));
	return ret;
}

void reconstruct(int pos1, int pos2) {
	if (max(pos1, pos2) == W + 1) return;

	int next = max(pos1, pos2) + 1;
	if (cache[next][pos2] + dist(pos1, next) < cache[pos1][next] + dist(pos2, next)) {
		cout << 1 << '\n';
		reconstruct(next, pos2);
	}
	else {
		cout << 2 << '\n';
		reconstruct(pos1, next);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> N >> W;
	v.resize(W + 2);

	for (int i = 2; i <= W + 1; i++)
		cin >> v[i].first >> v[i].second;

	v[0] = { 1, 1 };  //1번차 시작
	v[1] = { N, N };  //2번차 시작

	memset(cache, 0, sizeof(cache));

	cout << mindist(0, 1) << '\n';
	reconstruct(0, 1);


	return 0;

}