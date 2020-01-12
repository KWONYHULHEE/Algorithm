#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;



const int INF = 987654321;

int N, H;

vector<int> bot, top;



int main()

{

	cin >> N >> H;

	bot = vector<int>(N / 2, 0), top = vector<int>(N / 2, 0);

	for (int i = 0; i < N / 2; ++i)

		cin >> bot[i] >> top[i];

	sort(bot.begin(), bot.end()), sort(top.begin(), top.end());



	int ret = INF;

	int cnt = 1;


	for (int i = 1; i <= H; ++i)

	{


		int cand = distance(lower_bound(bot.begin(), bot.end(), i), bot.end());

		// top은 거꾸로 되어있으므로 i가 아닌 H+1-i를 해주어야 한다.
	//	cout << lower_bound(bot.begin(), bot.end(), i)- bot.begin() << " ";
		cand += distance(lower_bound(top.begin(), top.end(), H + 1 - i), top.end());
		//cout << lower_bound(top.begin(), top.end(), H + 1 - i)-top.begin() << "\n";


		// 똑같은 구간이 또 발견되었을 시

		if (ret == cand)

			cnt++;

		// 더 작은 구간이 발견되었을 시 

		if (ret > cand)

		{

			ret = cand;

			cnt = 1;

		}

	}
	cout << ret << " " << cnt << "\n";

	return 0;

}