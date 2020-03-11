#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
const int MAX_SIZE = 10010;
int arr[MAX_SIZE];

bool check(int x) {

	int sum = 0;

	for (int i = 0; i < N; i++) {
		int temp = arr[i] < x ? arr[i] : x;
		sum += temp;
	}

	if (sum <= M) return true;
	else return false;

}
int main() {

	cin.sync_with_stdio(false);
	cin.tie(NULL);

	int MAX = 0;
	cin >> N ;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		MAX = MAX < arr[i] ? arr[i] : MAX;
	}
	cin >> M;

	int left = 0;
	int right = MAX;
	int MAX_len = 0;

	while (left <= right) {
		int mid = (left + right) / 2;    
	
		if(check(mid)){
			MAX_len = mid;
			left = mid + 1; 
		}
		else right = mid - 1;  
	}
	cout << MAX_len << "\n";

	return 0;
}