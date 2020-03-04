#include<iostream>
#include <algorithm>
using namespace std;

int a, b, c, d;

int dfs(int x, int y, int swit, int cnt) {


	if (x == c && y == d) {
		return cnt;
	}

	if (swit == 0) {
		if (x<c)
			dfs(x + 1, y, 1, cnt + 1);
		else
			dfs(x - 1, y, 1, cnt + 1);
	}

	else if (swit == 1) {
		if (y<d)
			dfs(x, y + 1, 0, cnt + 1);
		else
			dfs(x, y - 1, 0, cnt + 1);
	}

}
int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
	
		cin >> a >> b;
		cin >> c >> d;

		int result = dfs(a, b, 0, 0) > dfs(a, b, 1, 0) ? dfs(a, b, 1, 0) : dfs(a, b, 0, 0);

		cout << "#" << t << " " << result << "\n";

	}

	return 0;
}