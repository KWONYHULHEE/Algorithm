#include <stdio.h>
#include <algorithm>
using namespace std;


int arr[100010];
int n;
int x = 0;
int y = 0;

int main() {

	//Please Enter Your Code Here

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);

	// for(int i=0;i<n;i++){
	//   printf("%d ",arr[i]);
	// }
	int i = 0;
	int j = n - 1;
	int min = arr[0] + arr[n - 1];
	x = arr[0];
	y = arr[n - 1];
	while (i != j) {
		// printf("%d ",abs(arr[i]+arr[j]));
		if (abs(min) > abs(arr[i] + arr[j])) {
			min = arr[i] + arr[j];
			x = arr[i];
			y = arr[j];
			// printf("%d %d",x,y);
		}

		if (arr[i] + arr[j] < 0) i++;
		else j--;
	}

	printf("%d %d", x, y);

	return 0;
}