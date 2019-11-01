#include <stdio.h>
int k;
int arr[20];
int res[20];
int res2[20];
bool check[20];
bool check2[20];
int cnt = 0;
int cnt2 = 0;
void inequal(int x) {

	if (x == k + 1) {
		for (int i = 0; i < x; i++) {
			if (arr[i] == '<')
			{
				if (res[i] > res[i + 1]) return;
			}
			else if (arr[i] == '>') {
				if (res[i] < res[i + 1]) return;

			}
		}
		if (cnt != 0) return;
		cnt++;
		for (int i = 0; i < k + 1; i++) {
			printf("%d", res[i]);
		}
		printf("\n");


	}

	else {
		for (int i = 9; i >= 0; i--) {
			if (check[i] == false) {
				check[i] = true;
				res[x] = i;
				inequal(x + 1);
				check[i] = false;
			}
		}
	}
}
void inequal2(int x) {

	if (x == k + 1) {
		for (int i = 0; i < x; i++) {
			if (arr[i] == '<')
			{
				if (res2[i] > res2[i + 1]) return;
			}
			else if (arr[i] == '>') {
				if (res2[i] < res2[i + 1]) return;

			}
		}
		if (cnt2 != 0) return;
		cnt2++;
		for (int i = 0; i < k + 1; i++) {
			printf("%d", res2[i]);
		}
		printf("\n");


	}

	else {
		for (int i = 0; i < 10; i++) {
			if (check2[i] == false) {
				check2[i] = true;
				res2[x] = i;
				inequal2(x + 1);
				check2[i] = false;
			}
		}
	}
}




int main() {

	//Please Enter Your Code Here
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf(" %c", &arr[i]);
	}


	inequal(0);
	inequal2(0);
	return 0;
}