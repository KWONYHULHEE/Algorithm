#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Time {
	int begin; // 회의 시작
	int end; // 회의 끝
};

bool cmp(Time f, Time s) {
	if (f.end == s.end)
		return f.begin < s.begin; // 종료시간이 같다면, 시작시간이 빠른 순
	else
		return f.end < s.end; // 같지 않다면, 종료시간이 빠른순으로 정렬
}

int main() {
	int N;
	cin >> N;

	vector<Time> t(N);
	for (int i = 0; i < N; i++) {
		cin >> t[i].begin >> t[i].end;
	}

	sort(t.begin(), t.end(), cmp); // 정렬

	int cnt = 0; // 회의 가능한 수
	int n = 0; // 회의 종료지점 저장

	for (int i = 0; i < t.size(); i++) {
		if (n <= t[i].begin) { // 회의 종료 지점이 다음 회의 시작지점보다 작으면
			n = t[i].end; // n에 다음 회의 종료 지점 저장
			cnt++; // 회의 가능수 증가
		}
	}

	cout << cnt << endl;
}
