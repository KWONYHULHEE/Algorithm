#include <iostream>
using namespace std;

int d[1010][1010];
int list[1010][1010];
int main() {

	int h, w, n;
	cin >> h >> w >> n;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++)
			cin >> list[i][j];
	}

	// N-1번째 산책후의 경로 세팅
	d[1][1] = n - 1;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (d[i][j] == 0)           // 가보지 않을곳은 스킵
				continue;

			d[i + 1][j] += d[i][j] / 2; // 절반은 아래쪽
			d[i][j + 1] += d[i][j] / 2; // 절반은 오른쪽

			if (d[i][j] % 2 == 1) {  // 홀수 횟수면
				if (list[i][j] == 1)    // 현재 상태에 따라 왼,오 추가
					d[i][j + 1]++;
				else
					d[i + 1][j]++;
			}

			list[i][j] = (list[i][j] + d[i][j]) % 2; // 마지막상태 저장
		}
	}

	// N번째 산책출발
	int i = 1, j = 1;
	while (i <= h && j <= w) {
		if (list[i][j] == 1)
			j++;
		else
			i++;
	}

	cout << i << " " << j << "\n";
	return 0;
}