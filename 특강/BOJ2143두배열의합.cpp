#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int a[1010];
int b[1010];

/*

upper_bound
lower_bound �˰��� ���.
�ּҰ��� ��ȯ�ϹǷ�, �� ���� �ּҰ��� ����� �ε��� ��ȯ ����!

1. A�� ���� �� �ִ� �ι迭�� ���� �̸� �� ���Ѵ�.
2. B�� ���� �� �ִ� �ι迭�� ���� �̸� �� ���Ѵ�.
3. B�� ���� (���̳ʸ� ��ġ�� ����)
4. A�� ���Ҹ� �ϳ��� Ž���ϸ� T���� ���� ���� B�� �� �� �����ϴ� ���� ã�´�.

**
upper_bound(num) - lower_bound(num)�� �ϸ� num�� ������
�ٷ� ���� �� �ִ�.

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



