#include <stdio.h>
#include <string.h>

const int MAX = 1010;
char arr[MAX];
int str[MAX][MAX];

int main() {

	//Please Enter Your Code Here
	scanf("%s", arr);
	int len = strlen(arr);


	for (int i = len - 1; i >= 0; i--) {
		for (int j = 0; j < len; j++) {
			if (i == j)
				str[i][j] = 0;

			else if (i < j) {
				if (arr[i] == arr[j])
					str[i][j] = str[i + 1][j - 1];

				else {
					if (str[i + 1][j] < str[i][j - 1])
						str[i][j] = str[i + 1][j] + 1;
					else
						str[i][j] = str[i][j - 1] + 1;
				}
			}
			else
				str[i][j] = 0;

		}
	}

	// for(int i=0;i<len;i++){
	//   for(int j=0;j<len;j++){
	//     printf("%d ",str[i][j]);
	//   }
	//   printf("\n");
	// }

	printf("%d", str[0][len - 1]);
	return 0;
}