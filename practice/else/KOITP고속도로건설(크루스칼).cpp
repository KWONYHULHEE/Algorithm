#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
https://snacky.tistory.com/52

ũ�罺Į MST


*/
const int MAX = 50010;
int m, n;
vector <pair<int,pair<int, int>>> adj;
int parent[MAX];

int find(int a) {
	if (parent[a] == a) return a;
	else return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	parent[a] = b;
}

bool sameparent(int a, int b) {
	if (find(a) == find(b)) return true;
	else return false;
}

int main() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj.push_back({ c, { a,b } });
	}
	sort(adj.begin(), adj.end());
	int res = 0;
	for (int i = 0; i < adj.size(); i++) {
		if (!sameparent(adj[i].second.first, adj[i].second.second)) {
			Union(adj[i].second.first, adj[i].second.second);
			res += adj[i].first;
		}
	}

	cout << res;

	return 0;
}