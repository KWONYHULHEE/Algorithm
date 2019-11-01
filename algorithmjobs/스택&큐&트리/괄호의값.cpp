#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

const int MAX = 50;
stack <char> s;
char arr[MAX];

int main() {

	//Please Enter Your Code Here

	scanf("%s", arr);
	int len = strlen(arr);

	int res = 1;
	int sum = 0;

	for (int i = 0; i < len; i++) {


		if (arr[i] == '(') {
			res *= 2;
			s.push(arr[i]);

			if (arr[i + 1] == ')'&&i + 1 < len) {
				sum += res;
			}
		}
		else if (arr[i] == '[') {
			res *= 3;
			s.push(arr[i]);

			if (arr[i + 1] == ']'&&i + 1 < len) {
				sum += res;
			}
		}

		if (!s.empty()) {
			if (arr[i] == ')') {
				res /= 2;
				if (s.top() == '(') {
					s.pop();
				}
			}
			else if (arr[i] == ']') {
				res /= 3;
				if (s.top() == '[') {
					s.pop();
				}
			}
		}
		else {
			printf("0");
			return 0;
		}

	}

	if (!s.empty()) {
		printf("0");
		return 0;
	}

	else printf("%d", sum);


	return 0;
}