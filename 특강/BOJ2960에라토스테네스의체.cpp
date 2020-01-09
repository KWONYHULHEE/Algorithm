#include <cstdio>
#include <math.h>
using namespace std;

int arr[1010];

int main(){


	int n,k;
	scanf("%d %d", &n,&k);
	int cnt = 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n / i; j++) {
			
			if (arr[i*j] == 0) 
				cnt++;
			
			
			arr[i*j] = 1;
			
			if (cnt == k) {
				printf("%d\n", i*j);
				return 0;
			}

		}
	}


	return 0;
}