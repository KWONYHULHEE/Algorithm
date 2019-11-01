#include <stdio.h>
int n;
const int MAX = 100010;
bool check[MAX];
int arr[MAX];


int maxsum(int s, int e) {

	if (s >= e)  return arr[s];
	int mid = (s + e) / 2;
	int left = maxsum(s, mid);
	int right = maxsum(mid + 1, e);

	int leftsum = 0; int leftmax = -12345;
	for (int i = mid; i >= s; i--) {
		leftsum += arr[i];
		if (leftsum > leftmax)
			leftmax = leftsum;
	}

	int rightsum = 0; int rightmax = -12345;
	for (int i = mid + 1; i <= e; i++) {
		rightsum += arr[i];
		if (rightsum > rightmax)
			rightmax = rightsum;
	}

	int midmax = leftmax + rightmax;

	if (left <= right && right >= midmax) return right;
	else if (left >= right && left >= midmax) return left;
	else return midmax;

}


int main() {

	//Please Enter Your Code Here
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int res = maxsum(0, n - 1);
	printf("%d", res);


	return 0;
}