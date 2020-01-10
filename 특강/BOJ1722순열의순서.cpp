#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long f[21]; // 1!~20! 까지 값을 저장할 변수
bool check[21]; // 1~N까지의 숫자가 순열에 있는지 없는지 확인하는 변수

int main()
{
	int N, cmd;

	cin >> N;

	f[0] = 1;

	// 팩토리얼 초기화
	for (int i = 1; i < 21; i++)
		f[i] = f[i - 1] * i;

	cin >> cmd;

	// 몇 번째 순열인지 출력하기.
	if (cmd == 2)
	{
		vector<int> a(N);

		// 순열 입력
		for (int i = 0; i < N; i++)
			cin >> a[i];

		long long ans = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j < a[i]; j++)
			{
				// 1부터 해당하는 원소까지 팩토리얼 값을 늘려가며 더해준다.
				if (check[j] == false)
					ans += f[N - i - 1];
			}
			// 순열에 존재하는 숫자는 있다고 표시해준다.
			check[a[i]] = true;
		}

		cout << ans + 1 << "\n";
	}
	// k 번째 순열 출력하기
	else
	{
		long long k;

		cin >> k;

		vector<int> a(N);

		// k번째 순열 찾는 과정
		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				// 순열에 이미 존재하는 숫자면 넘어간다
				if (check[j] == true) continue;
				// 팩토리얼 값이 k보다 작으면 k에서 팩토리얼 값을 빼준다
				if (f[N - i - 1] < k)
				{
					k -= f[N - i - 1];
				}
				// 팩토리얼 값이 k보다 크면 해당하는 원소의 숫자를 찾은 것. 
				// a[i]에 저장하고 순열에 존재하는 숫자를 체크해준다
				else
				{
					a[i] = j;
					check[j] = true;
					break;
				}
			}
		}

		for (int i = 0; i < N; i++) cout << a[i] << " ";
		cout << "\n";
	}

	return 0;
}