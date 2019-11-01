#include <cstdio>    

int N, X;
int map[20][20];

int Solve();

int main(void)
{
	int T;
	scanf("%d", &T);

	for (int tc = 0; tc < T; tc++)
	{
		scanf("%d %d", &N, &X);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &map[i][j]);

		printf("#%d %d\n", tc + 1, Solve());
	}

	return 0;
}


int Solve()
{
	int count = 2 * N;

	// 가로 방향 검사    
	for (int x = 0; x < N; x++)
	{
		bool cache[20] = { 0 }; // cache[y][h] : (y, h)에 경사면이 설치되었는지?    

		for (int y = 0; y < N - 1; y++)
		{
			int diff = map[x][y + 1] - map[x][y];

			// 올라가는 경사면이 필요하다.    
			if (diff > 0)
			{
				bool possible = true;

				// 설치 가능한 지형인지 확인한다.    
				// 만약 설치 가능한 지형이라면 이미 경사면이 설치된 곳인지 확인한다.    
				for (int temp = y; temp >= (y - X + 1); temp--)
				{
					if (temp < 0 || map[x][y + 1] - 1 != map[x][temp])
					{
						possible = false;
						break;
					}
					else
					{
						if (cache[temp])
						{
							possible = false;
							break;
						}
					}
				}

				if (!possible)
				{
					count--;
					break;
				}

				// 경사면을 설치한다.    
				for (int temp = y; temp >= (y - X + 1); temp--)
					cache[temp] = true;
			}
			// 내려가는 경사면이 필요하다.     
			else if (diff < 0)
			{
				bool possible = true;

				for (int temp = y + 1; temp <= (y + X); temp++)
				{
					if (temp >= N || map[x][y] - 1 != map[x][temp])
					{
						possible = false;
						break;
					}
					else
					{
						if (cache[temp])
						{
							possible = false;
							break;
						}
					}
				}

				if (!possible)
				{
					count--;
					break;
				}

				for (int temp = y + 1; temp <= (y + X); temp++)
					cache[temp] = true;
			}
		}
	}

	// 세로 방향 검사    
	for (int y = 0; y < N; y++)
	{
		bool cache[20] = { 0 }; // cache[x][h] : (x, h)에 경사면이 설치되었는지?    

		for (int x = 0; x < N - 1; x++)
		{
			int diff = map[x + 1][y] - map[x][y];

			// 올라가는 경사면이 필요하다.    
			if (diff > 0)
			{
				bool possible = true;

				// 설치 가능한 지형인지 확인한다.    
				// 만약 설치 가능한 지형이라면 이미 경사면이 설치된 곳인지 확인한다.    
				for (int temp = x; temp >= (x - X + 1); temp--)
				{
					if (temp < 0 || map[x + 1][y] - 1 != map[temp][y])
					{
						possible = false;
						break;
					}
					else
					{
						if (cache[temp])
						{
							possible = false;
							break;
						}
					}
				}

				if (!possible)
				{
					count--;
					break;
				}

				// 경사면을 설치한다.    
				for (int temp = x; temp >= (x - X + 1); temp--)
					cache[temp] = true;
			}
			// 내려가는 경사면이 필요하다.     
			else if (diff < 0)
			{
				bool possible = true;

				for (int temp = x + 1; temp <= (x + X); temp++)
				{
					if (temp >= N || map[x][y] - 1 != map[temp][y])
					{
						possible = false;
						break;
					}
					else
					{
						if (cache[temp])
						{
							possible = false;
							break;
						}
					}
				}

				if (!possible)
				{
					count--;
					break;
				}

				for (int temp = x + 1; temp <= (x + X); temp++)
					cache[temp] = true;
			}
		}
	}

	return count;
}
