#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 1010;
char arr[MAX];
char str[MAX];
int d[MAX][MAX];

int main() {

	//Please Enter Your Code Here
	scanf("%s", arr);
	scanf("%s", str);

	int alen = strlen(arr);
	int blen = strlen(str);

	for (int i = 0; i <= alen; i++) {
		d[0][i] = i;
	}
	for (int i = 0; i <= blen; i++) {
		d[i][0] = i;
	}

	for (int i = 1; i <= blen; i++) {
		for (int j = 1; j <= alen; j++) {

			if (str[i - 1] == arr[j - 1])
				d[i][j] = d[i - 1][j - 1];


			else
				d[i][j] = min(d[i - 1][j], d[i][j - 1]) + 1;
		}
	}

	printf("%d\n", d[blen][alen]);

	// for(int i=0;i<=blen;i++){
	//   for(int j=0;j<=alen;j++){
	//     printf("%d ",d[i][j]);
	//   }
	//   printf("\n");
	// }
	return 0;
}