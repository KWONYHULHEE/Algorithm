#include <iostream>
#include <string>
#include <algorithm>

const int MAX = 1010;
using namespace std;

int n, m;
int MAP[MAX][MAX];
int DP[MAX][MAX];


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			MAP[i][j] = s[j] - '0';
		}
	}

	int Max_Len = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (MAP[i][j] != 0)
			{
				MAP[i][j] = min(MAP[i - 1][j - 1], min(MAP[i - 1][j], MAP[i][j - 1])) + 1;
				if (Max_Len < MAP[i][j]) Max_Len = MAP[i][j];
			}
		}
	}

	cout << Max_Len * Max_Len << endl;

	return 0;
}
