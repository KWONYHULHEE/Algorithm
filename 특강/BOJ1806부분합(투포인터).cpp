#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;
const int INF = 987654321;
int arr[MAX];

int main(void)

{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, S;
	cin >> N >> S;



	for (int i = 0; i < N; i++)

		cin >> arr[i];



	int low = 0, high = 0;
	int sum = arr[0];
	int result = INF;



	while (low <= high && high < N)

	{

		if (sum < S)
			sum += arr[++high];

		else if (sum == S){

			result = min(result, (high - low + 1));
			sum += arr[++high];

		}

		else if (sum > S){

			result = min(result, (high - low + 1));
			sum -= arr[low++];

		}
	}



	if (result == INF) cout << 0 << "\n";
	else cout << result << "\n";

	return 0;

}

