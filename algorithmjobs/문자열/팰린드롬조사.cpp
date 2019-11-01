#include <stdio.h>
#include <string.h>
int main() {

	//Please Enter Your Code Here
	char arr[1010];

	fgets(arr, sizeof(arr), stdin);


	int len = strlen(arr);
	for (int i = 0; i < len / 2;)
	{
		if (arr[i] == arr[len - i - 1]) {
			i++;
		}
		else
		{
			printf("NO");
			return 0;
		}
	}

	printf("YES");

	return 0;
}