
/*

 데이터의 개수  n 에 4를 곱한 크기만큼 미리 구간 합 트리의 공간을 할당.
 https://m.blog.naver.com/ndb796/221282210534 참고
*/

#include <iostream>
#include <vector>
#include <queue>
#include<string>
#include <algorithm>
#include <cstring> //memset

using namespace std;
const long long MAX = 1000000 + 2;


const int INF = 87654321;
long long N, M, K;
long long seg[MAX * 4] = {};
long long arr[MAX] = {};
struct Segtree {

	long long sum(int left, int right, int node, int start, int end) {
		if (start > right || end < left) return 0;
		if (left <= start && end <= right) return seg[node];
		int mid = (start + end) / 2;
		return (sum(left, right, node * 2, start, mid) + sum(left, right, node * 2 + 1, mid + 1, end));
	}

	long long update(int index, int value, int node, int start, int end) {


		if (index < start || end < index) return seg[node];

		if (start == end) return seg[node] = value;
		int mid = (start + end) / 2;
		return seg[node] = (long long)update(index, value, node * 2, start, mid) + update(index, value, node * 2 + 1, mid + 1, end);
	}

	long long init(int start, int end, int node) {

		if (start == end) return seg[node] = arr[start];
		int mid = (start + end) / 2;
		return seg[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);

	}
};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	Segtree Tree;

	for (int i = 1; i <= N; i++) {
		long long k;
		cin >> k;
		arr[i] = k;
	}

	Tree.init(1, N, 1);  //트리구현

	long long a, b, c;
	for (int i = 1; i <= M + K; i++) {
		cin >> a >> b >> c;

		if (a == 1) {
			Tree.update(b, c, 1, 1, N);
			continue;
		}

		if (a == 2) {
			long long ans = Tree.sum(b, c, 1, 1, N);
			cout << ans << endl;
			continue;
		}

	}
	return 0;
}

