#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 2500;
double arr[MAX + 1][MAX + 1];

int main() {

	int m, k;

	for (int i = 0; i < MAX + 1; i++) {
		arr[i][0] = 1;
		arr[i][i] = 1;
	}

	for (int i = 2; i < MAX + 1; i++) {
		for (int j = 1; j <= i; j++) {
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];

		}
	}


	scanf("%d", &m);
	int sum = 0;
	double value = 0;
	vector <int> v;

	for (int i = 0; i < m; i++) {
		int n;
		scanf("%d", &n);
		sum += n;
		v.push_back(n);
	}

	scanf("%d", &k);

	for (int i = 0; i < m; i++) {
		value += arr[v[i]][k];
	}

	double res = arr[sum][k];


	printf("%.18lf", value / res);


	return 0;
}