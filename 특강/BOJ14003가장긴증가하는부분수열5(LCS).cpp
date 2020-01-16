#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, arr[1000001], p[1000001], cnt;
vector<int> ans, print;

/*

부분 수열의 정답을 저장하기 위한 어레이와 출력에 사용될 각 원소의 위치를 저장해주기 위한 어레이를 하나 생성한다. 여기에는 각 부분 수열의 값이 업데이트되어 들어간다.
새로운 원소가 ans 어레이에 있는 맨 끝 원소보다 클 경우에는 뒤에다가 push_back 해준다.
만일 그게 아니라면 어레이 중간에서 어느 원소의 값을 대체할 수 있는지 lower_bound를 이용해서 찾는다.
그리고 현재 원소가 들어간 인덱스를 p 어레이에 저장한다.
모든 과정이 끝나고 나면 p를 이용해 각 위치의 수를 뒤에서부터 역순으로 하나씩 꺼낸다.

*/

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

	ans.push_back(arr[1]);

	for (int i = 2; i <= n; i++) {
		if (ans[cnt] < arr[i]) {
			ans.push_back(arr[i]), cnt++;
			p[i] = cnt;
		}
		else {
			int pos = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
			ans[pos] = arr[i];
			p[i] = pos;
		}
	}

	printf("%d\n", cnt + 1);

	for (int i = n; i >= 1 && cnt >= 0; i--) {
		if (p[i] == cnt) {
			print.push_back(arr[i]);
			cnt--;
		}
	}

	for (int i = print.size() - 1; i >= 0; i--) {
		printf("%d ", print[i]);
	}
}
