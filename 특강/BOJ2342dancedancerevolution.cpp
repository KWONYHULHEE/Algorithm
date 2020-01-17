#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100010;
int arr[MAX];
int d[MAX][5][5];

int power(int from, int to) {

	if (from == 0) return 2;
	if (abs(from - to) == 2) return 4;
	if (from == to) return 1;
	return 3;

}


int main() {

	int index = 1;

	while (1) {
		int a;
		cin >> a;
		if (a == 0) break;
		arr[index++] = a;

	}

	int n = index-1;


	for (int k = 0; k < MAX; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
					d[k][i][j] = 987654321;
				}
			}
		}
	

	//k번째 스텝 왼발i오른발j
	d[1][arr[1]][0] = 2;
	d[1][0][arr[1]] = 2;
	d[0][0][0] = 0;

	for (int k = 2; k <= n; k++) {  //   k  번째 스텝
		for (int i = 0; i < 5; i++) { //왼발
			for (int j = 0; j < 5; j++) {  //오른발
				if (i == j) continue;  //같은경우는 존재안함
				if (i != arr[k] && j != arr[k]) continue; //왼발이나 오른발 둘중 하나는 다음스텝에 갈 위치여야함 
				for (int z = 0; z < 5; z++) {
					if (i == arr[k]) d[k][i][j] = min(d[k][i][j], d[k - 1][z][j] + power(z, i)); //왼발일경우 전스텝에서 z위에서 이번i값위로 발이 와야댐
					if (j == arr[k]) d[k][i][j] = min(d[k][i][j], d[k - 1][i][z] + power(z, j)); 
				}
			}
		}
	}


	int res = 987654321;
	for (int i = 0; i < 5; i++) {
		if (i == arr[n]) continue;   //둘다 같은발일수가없음 
		res = min(res, d[n][arr[n]][i]);
		res = min(res, d[n][i][arr[n]]);
	//	cout << d[n][arr[n]][i] << d[n][i][arr[n]] << endl;
	}


	if (res >= 987654321) cout << "0\n";
	else cout << res << "\n";
	
	

	return 0;
}