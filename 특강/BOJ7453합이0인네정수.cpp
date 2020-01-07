#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int a[4010];
int b[4010];
int c[4010];
int d[4010];

vector <int> v1;
vector <int> v2;
long long int result = 0;

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v1.push_back(a[i] + b[j]);
			v2.push_back(c[i] + d[j]);
		}
	}


	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	for (int i = 0; i < v2.size(); i++) {

		int up = upper_bound(v1.begin(), v1.end(), v2[i] * -1) - v1.begin();
		int low = lower_bound(v1.begin(), v1.end(), v2[i] * -1) - v1.begin();

		result += (up - low);
	}

	printf("%lld", result);

	return 0;
}