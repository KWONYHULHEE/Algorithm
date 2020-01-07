#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 100010;
int arr[MAX][3];
int big[2][3];
int small[2][3];


int main() {

	int n;

	scanf("%d", &n);
	
	for (int i = 1; i <=n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		
		}
	}


	small[0][0] = big[0][0] = arr[1][0];
	small[0][1] = big[0][1] = arr[1][1];
	small[0][2] = big[0][2] = arr[1][2];

	for (int i = 2; i <= n; i++)
	{
		big[1][0] = arr[i][0] + max(big[0][0], big[0][1]);
		big[1][1] = arr[i][1] + max(big[0][0], max(big[0][1], big[0][2]));
		big[1][2] = arr[i][2] + max(big[0][1], big[0][2]);

		big[0][0] = big[1][0];
		big[0][1] = big[1][1];
		big[0][2] = big[1][2];

		small[1][0] = arr[i][0] + min(small[0][0], small[0][1]);
		small[1][1] = arr[i][1] + min(small[0][0], min(small[0][1], small[0][2]));
		small[1][2] = arr[i][2] + min(small[0][1], small[0][2]);

		small[0][0] = small[1][0];
		small[0][1] = small[1][1];
		small[0][2] = small[1][2];
	}

	int resultbig = max(big[0][0], max(big[0][1], big[0][2]));
	int resultsmall = min(small[0][0], min(small[0][1], small[0][2]));


	printf("%d %d\n", resultbig, resultsmall);

	
	return 0;
}






