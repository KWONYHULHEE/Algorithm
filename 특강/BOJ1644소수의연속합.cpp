#include <iostream>
#include <vector>
using namespace std;

int arr[4000010];
vector <int> v;

int main() {

	int n;
	scanf("%d", &n);
	int answer = 0;

	arr[0] = 1;
	arr[1] = 1;

	for (int i = 2; i <=n; i++) {
		for (int j = 2; j <=n /i; j++) {
			arr[i*j] = 1;
		}
	}  //소수면 0



	for (int i = 2; i <= n; i++) {  // N까지 모든 소수를 저장한다
		if (arr[i] == 0) {
			v.push_back(i);
		}
	}

	int sum = 0, head = 0, tail = 0;    // 부분합문제처럼 투포인터로 N과 동일한 값 개수를 카운팅 한다

	for (int i = 0; i<v.size(); i++) {
		sum += v[head++];
		while (sum >n) {
			sum -= v[tail++];
		}
		if (sum == n) {
			//cout << arr[20];
			answer++;
		}
	}

	cout << answer;



	return 0;
}




