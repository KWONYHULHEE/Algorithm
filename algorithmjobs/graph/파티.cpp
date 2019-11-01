#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100010;
vector <int> graph[MAX];
vector <int> cost[MAX];
vector <int> reversegraph[MAX];
vector <int> reversecost[MAX];
int n, m;
int table[MAX];
int table2[MAX];
int k = 0;
bool check2[MAX] = { 0, };
bool check[MAX] = { 0, };

void find(vector<int> graph[MAX], vector <int> cost[MAX], int table[MAX], bool check[MAX], int start) {

	for (int i = 0; i <= n; i++) table[i] = 983472831;

	table[start] = 0;

	for (int i = 1; i <= n; i++) {

		int minvalue = 93345334, minindex = -1;

		for (int j = 1; j <= n; j++) {
			if (!check[j] && minvalue > table[j]) {
				minvalue = table[j];
				minindex = j;
			}
		}

		check[minindex] = true;

		for (int j = 0; j < graph[minindex].size(); j++) {
			int node2 = graph[minindex][j];
			int cost2 = cost[minindex][j];

			if (table[node2] > table[minindex] + cost2) {
				table[node2] = table[minindex] + cost2;
			}
		}
	}

}


int main() {

	//Please Enter Your Code Here
	scanf("%d %d %d", &n, &m, &k);
	int result = 0;

	for (int i = 0; i < m; i++) {
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		graph[a].push_back(b);
		reversegraph[b].push_back(a);

		cost[a].push_back(c);
		reversecost[b].push_back(c);

	}


	find(graph, cost, table, check, k);
	find(reversegraph, reversecost, table2, check2, k);

	for (int i = 1; i <= n; i++) {
		result += (table[i] + table2[i]);
	}

	printf("%d\n", result);

	// printf("%d\n",table[q]);
	return 0;
}