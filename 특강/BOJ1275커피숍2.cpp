#include <iostream>
using namespace std;

const long long MAX = 100000 + 2;

long long N, Q;
long long seg[MAX * 4] = {};
long long arr[MAX] = {};



	long long sum(int left, int right, int node, int start, int end) {

		if (start > right || end < left) return 0;
		if (start >= left && end <= right) return seg[node];

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


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >>Q;


	for (int i = 1; i <= N; i++) {
		long long k;
		cin >> k;
		arr[i] = k;
	}

	init(1, N, 1);  

	

	for (int i = 0; i <Q; i++) {
		long long x, y, a, b;

		cin >> x >> y >> a>> b;

		if (x > y)
			swap(x, y);

			long long ans = sum(x, y, 1, 1, N);
			cout << ans <<"\n";

			update(a, b, 1, 1, N);
		

	}
	return 0;
}
