
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
	
		long long query(int l, int r, int node, int nodeL, int nodeR) {
		if (nodeL>r || nodeR<l) return 0;//항등원
		if (l <= nodeL && nodeR <= r) return seg[node];
		int mid = (nodeL + nodeR) / 2;
		return (query(l, r, node * 2, nodeL, mid) + query(l, r, node * 2 + 1, mid + 1, nodeR));
	}

	long long update(int index, int value, int node, int S, int E) {
		//index : 수정하고자하는 노드 value : 수정할 값

		if (index<S || E < index) return seg[node];
		if (S == E) return seg[node] = value;
		int mid = (S + E) / 2;

		return seg[node] = (long long)update(index, value, node * 2, S, mid) + update(index, value, node * 2 + 1, mid + 1, E);
	}

	long long init(int l, int r, int node) {

		if (l == r) return seg[node] = arr[l];
		int mid = (l + r) / 2;
		return seg[node] = init(l, mid, node * 2) + init(mid + 1, r, node * 2 + 1);

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
			long long ans = Tree.query(b, c, 1, 1, N);
			cout << ans << endl;
			continue;
		}

	}
	return 0;
}

