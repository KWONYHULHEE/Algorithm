#include <cstdio>
#include <stack>
using namespace std;
int n;
const int MAX = 500100;
int arr[MAX];
stack <int> s;

int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	int i = 1;

	while (1) {

		if (i > n)
			break;

		if (s.empty()) {
			printf("0 ");
			s.push(i);
			i++;
			continue;
		}
		if (arr[s.top()] < arr[i]) {
			s.pop();
			continue;
		}

		if (arr[s.top()] > arr[i]) {
			printf("%d ", s.top());
			s.push(i);
			i++;
		}

		if (arr[s.top()] == arr[i]) {
			printf("%d ", s.top());
			s.pop();
			s.push(i);
			i++;
		}
	}

	return 0;
}