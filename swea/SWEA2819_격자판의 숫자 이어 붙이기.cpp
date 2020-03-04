#include <string>
#include <math.h>
#include <iostream>
#include <set>
using namespace std;

int num = 0;
int arr[4][4];
set<int> setary;
int nx[4] = { 0, 0, -1, 1 };
int ny[4] = { -1, 1, 0, 0 };

void dfs(int x, int y, int val, int dept) {
	
	if (dept == 7) {
		setary.insert(val);
		return;
	}

	for (int i = 0; i < 4; i++) {
		
		int dx = x + nx[i];
		int dy = y + ny[i];

		if (dx < 0 || dx >= 4 || dy < 0 || dy >= 4) continue;
		
			dfs(dx, dy, val * 10 + arr[dx][dy], dept + 1);
		
	}
}
int main()
{
	cin >> num;
	for (int i = 1; i <= num; i++) {
		setary.clear();
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> arr[j][k];
			}
		}
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				dfs(j, k, arr[j][k], 1);
			}
		}
		cout << "#" << i << " " << setary.size() << endl;
	}
}