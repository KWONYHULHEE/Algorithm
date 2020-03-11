#include <iostream>
#include <string.h>

using namespace std;

int MAP[100], N, ans, sum;
bool check[10001];
void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = sum; j >= 0; j--)
		{
			if (check[j])
			{
				check[j + MAP[i]] = true;
			}
		}
	}

}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++)
	{
		ans = 0;
		sum = 0;
		cin >> N;
		memset(MAP, 0, sizeof(MAP));
		memset(check, false, sizeof(check));
		check[0] = true;

		for (int i = 0; i < N; i++)
		{
			cin >> MAP[i];
			sum += MAP[i];
		}
		solve();
		for (int i = 0; i <= sum; i++)
		{
			if (check[i])
				ans++;
		}
		cout << '#' << T << ' ' << ans << '\n';
	}
	return 0;
}

