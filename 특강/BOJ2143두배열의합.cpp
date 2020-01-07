#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int a[1010];
int b[1010];

/*

upper_bound
lower_bound 알고리즘 사용.
주소값을 반환하므로, 맨 앞의 주소값을 빼줘야 인덱스 반환 가능!

1. A로 만들 수 있는 부배열의 합을 미리 다 구한다.
2. B로 만들 수 있는 부배열의 합을 미리 다 구한다.
3. B를 정렬 (바이너리 서치를 위함)
4. A의 원소를 하나씩 탐색하며 T와의 차이 값이 B에 몇 개 존재하는 지를 찾는다.

**
upper_bound(num) - lower_bound(num)을 하면 num의 갯수를
바로 구할 수 있다.

*/

int main() {

	int T, N, M;
	vector <int> va;
	vector <int> vb;


	scanf("%d", &T);
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &b[i]);
	}

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += a[j];
			va.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++) {
		int sum = 0;
		for (int j = i; j < M; j++) {
			sum += b[j];
			vb.push_back(sum);
		}
	}

	sort(vb.begin(), vb.end());

	long long answer = 0;

	for (int i = 0; i<va.size(); i++)
	{
		int high = upper_bound(vb.begin(), vb.end(), T - va[i]) - vb.begin();
		int low = lower_bound(vb.begin(), vb.end(), T - va[i]) - vb.begin();

		answer += (long long)(high - low);
	}

	printf("%lld\n", answer);
	return 0;
}



