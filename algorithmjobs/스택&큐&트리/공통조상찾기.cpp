#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1010;
vector <int> arr[MAX];
int n, x, y;
int depth[MAX];
int parent[MAX];
bool check[MAX];

void find(int x, int dep) {
	check[x] = true;
	depth[x] = dep;

	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];

		if (!check[y]) {
			parent[y] = x;
			find(y, dep + 1);
		}
	}
}


int main() {

	//Please Enter Your Code Here
	cin >> n >> x >> y;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	find(0, 0);


	if (depth[x] < depth[y]) {

		while (1) {
			if (depth[x] == depth[y]) {
				if (x == y) {
					cout << x;
					return 0;
				}
				else break;
			}
			y = parent[y];
		}
	}
	else if (depth[x] > depth[y]) {

		while (1) {
			if (depth[x] == depth[y]) {
				if (x == y) {
					cout << x;
					return 0;
				}
				else break;
			}
			x = parent[x];
		}
	}

	if (depth[x] == depth[y]) {

		while (1) {

			if (x == y) {
				cout << x;
				return 0;
			}
			else {
				y = parent[y];
				x = parent[x];
			}
		}
	}



	return 0;
}