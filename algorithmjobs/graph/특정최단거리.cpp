#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100010;
int n, m, p, q;
vector <int> arr[MAX];
vector <int> cost[MAX];
int table[MAX];
int find(int s, int e) {
	bool check[MAX] = { 0, };
	for (int i = 1; i <= n; i++) table[i] = 987987987;
	table[s] = 0;

	for (int i = 1; i <= n; i++) {

		int minvalue = 987987987; int minindex = -1;
		for (int j = 1; j <= n; j++) {
			if (!check[j] && minvalue > table[j]) {
				minvalue = table[j];
				minindex = j;
			}
		}

		check[minindex] = true;


		for (int j = 0; j < arr[minindex].size(); j++) {
			int node2 = arr[minindex][j];
			int cost2 = cost[minindex][j];

			if (table[node2] > table[minindex] + cost2) {
				table[node2] = table[minindex] + cost2;
			}
		}
	}



	return table[e];



}



int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);
		arr[a].push_back(b);
		arr[b].push_back(a);

		cost[a].push_back(c);
		cost[b].push_back(c);
	}

	scanf("%d %d", &p, &q);
	int res1 = 0;
	int res2 = 0;
	res1 += find(1, p);
	res1 += find(p, q);
	res1 += find(q, n);

	res2 += find(1, q);
	res2 += find(q, p);
	res2 += find(p, n);

	printf("%d", min(res1, res2));




}