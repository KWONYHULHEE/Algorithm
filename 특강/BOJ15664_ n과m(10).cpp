#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m;
const int MAX = 50;
int res[MAX];
bool check[MAX];
int arr[MAX];


void tobin(int x) {

	bool check2[100010] = { 0, };

	if (x == m) {
		for (int i = 1; i < x ; i++) {
			if (arr[res[i - 1]] > arr[res[i]]) {
				return;
			}
		}
		for (int i = 0; i<x; i++) {
			printf("%d ", arr[res[i]]);
		}
		printf("\n");

	}
	else {
		for (int i = 0; i<n; i++) {
			if (check[i] == false && check2[arr[i]] == false) {
				check[i] = true;
				check2[arr[i]] = true;
				res[x] = i;
				tobin(x + 1);
				check[i] = false;
			}
		}
	}

}


int main() {

	//Please Enter Your Code Here
	scanf("%d %d", &n, &m);

	for (int i = 0; i<n; i++)
		scanf("%d", &arr[i]);

	sort(arr, arr + n);

	tobin(0);

	return 0;
}