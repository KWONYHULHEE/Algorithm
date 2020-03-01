#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n >> m;
		int area[110] = { 0, };
		int areaFare[110];
		int carWeight[2010];
		int Sunseo[4010];
		queue <int> q;
		int fare = 0;

		for (int i = 1; i <= n; i++)
			cin >> areaFare[i];

		for (int i = 1; i <= m; i++)
			cin >> carWeight[i];

		for (int i = 1; i <= 2 * m; i++)
			cin >> Sunseo[i];

		for (int i = 1; i <= 2 * m; i++) {

			if (Sunseo[i] > 0) {
				q.push(Sunseo[i]);
				bool flag = false;
				for (int j = 1; j <= n; j++) {
					if (area[j] == 0) {  //빈공간이 있어

						area[j] = q.front(); 
						fare += (carWeight[q.front()] * areaFare[j]);

						q.pop();
						if (q.empty()) flag = true;
					}
					if (flag == true) break;
				}
			}
			else {
				for (int j = 1; j <= n; j++) {
					if (area[j] == (-1)*Sunseo[i]) {

						area[j] = 0;
						if (!q.empty()) {
							area[j] = q.front();
							fare += (carWeight[q.front()] * areaFare[j]);

							q.pop();
						}
					}
				}
			}
		}

		cout << "#" << t << " " << fare << endl;
	}

	return 0;
}