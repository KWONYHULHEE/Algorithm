#include <stdio.h>
#include <string.h>

char arr[1010];
char str[1010];
int cnt[1010];


int main() {

	//Please Enter Your Code Here

	scanf("%s", arr);
	int k = 0;


	str[k] = arr[0];

	for (int i = 0; i < strlen(arr); i++)
	{
		if (str[k] == arr[i])
			cnt[k]++;
		else
		{
			k++;
			str[k] = arr[i];
			cnt[k]++;
		}
	}

	for (int i = 0; i < strlen(arr); i++)
	{
		if (cnt[i] == 0)
			break;
		if (cnt[i] == 1)
			printf("%c", str[i]);
		else
			printf("%d%c", cnt[i], str[i]);
	}

	return 0;
}