#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;
int res = 0;
char arr[100];

int main() {

	scanf("%s", arr);
	int len = strlen(arr);
	stack <char> s;



	for (int i = 0; i < len; i++) {
		if (arr[i] == '(') {
			s.push(arr[i]);
		}
		else if (arr[i] == ')')
		{
			if (s.size() != 0)
				s.pop();
			else {
				res = 1;
				break;
			}

		}
	}

	if (res == 0 && s.size() == 0)
		printf("YES");
	else
		printf("NO");





	return 0;
}