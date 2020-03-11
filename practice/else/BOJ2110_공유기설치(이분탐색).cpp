#include<iostream>
#include<algorithm>
using namespace std;

int N, C;
const int MAX_SIZE = 200001;
int arr[MAX_SIZE];

bool check(int x) {

	int cnt = 1;    // 0번째에는 공유기 설치했다고 가정하고 시작
	int start = arr[0];    // 0에 공유기 설치했으니까 시작점으로 두고, mid보다 크거나 같은 최초지점 찾으면, 그 점에 공유기 설치.

	for (int i = 1; i < N; i++)
	{
		if (arr[i] - start >= x) {
			start = arr[i];
			cnt++;
		}
	}
	// 위에서 공유기 갯수 모두 파악됨.

	if (cnt >= C)    // 설치된 공유기 갯수가 설치 가능 횟수보다 크거나 같으면
	{
		return true;
	}
	else return false;

}
int main() {

	cin.sync_with_stdio(false);
	cin.tie(NULL);

	int MAX = 0;
	cin >> N >> C;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		MAX = MAX < arr[i] ? arr[i] : MAX;
	}
	sort(arr, arr + N);    // 정렬

	int left = 1;
	int right = MAX;
	int MAX_len = 0;

	// 이분 탐색으로 가장 긴 거리를 구한다.
	while (left <= right) {

		int mid = (left + right) / 2;    // 중간값으로 지정
	
		if(check(mid)){
			MAX_len = mid;
			left = mid + 1; //거리를 늘려조야대
		}
		else right = mid - 1;  //거리를 좁혀조야대
	}
	cout << MAX_len << "\n";

	return 0;
}