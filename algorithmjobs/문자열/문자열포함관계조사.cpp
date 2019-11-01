#include <stdio.h>
#include <string.h>


char a[1010];
char b[1010];
int main() {

	//Please Enter Your Code Here

	scanf("%s", a);
	scanf("%s", b);
	int k = 0;
	int cnt = 0;

	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == b[k])
		{
			k++;
			cnt++;
			if (cnt == strlen(b))
			{
				printf("YES");
				return 0;
			}
		}
		else
		{
			k = 0;
			cnt = 0;
		}

	}
	printf("NO");

	return 0;
}