#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int bag[300010];
int n, k;
vector <pair<int, int>> v;
priority_queue<int,vector<int>,less<int>> pq;

int main() {

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		bag[i] = a;
	}


	sort(v.begin(), v.end());
	sort(bag, bag + k);

	long long int ans = 0;
	int j = 0;
	for (int i = 0; i < k; i++) {
		
		while (j < n&&v[j].first <= bag[i]) {
			pq.push(v[j].second);
			j++;
		}

		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans << endl;


	return 0;
}