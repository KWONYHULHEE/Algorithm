#include <iostream>
#include <algorithm>
using namespace std;

int list[1010];
int d[1010][1010];

//i에서 j까지의 카드가 남았을때


void init() {

	for (int i = 0; i < 1010; i++) {
		for (int j = 0; j < 1010; j++) {
			d[i][j] = 0;
		}
	}

}
int main() {

	int tc;
	int n;
	
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		cin >> n;
		init();

		fill(list, list + 1010, 0);

		for (int i = 1; i <= n; i++)
		{
			cin >> list[i];
			if (n % 2 == 1) d[i][i] = list[i]; //홀수면 마지막하나 근우꺼 아니면 하나만 남을수가없음 
		}

		for (int k = 1; k < n; k++) {  // 배열의 길이별로 짜르기 
			for (int i = 1; i <= n - k; i++) {
				int j = i + k;
				if (abs((i + j) % 2) == 0)  //근우
					d[i][j] = max(d[i + 1][j] + list[i], d[i][j - 1] + list[j]);

				else //명우
					d[i][j] = min(d[i + 1][j], d[i][j - 1]);
			}
		}


		cout << d[1][n]<<"\n";
	}

	return 0;
}