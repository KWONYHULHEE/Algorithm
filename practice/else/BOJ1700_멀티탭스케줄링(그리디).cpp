/*
 빈 포트가 없으면 현재 꽂혀 있는 아이템 중에
 나중에 가장 늦게 사용하는 아이템 포트를 뺸다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100];
bool use[100];
int tab[100];

int main() {

	ios::sync_with_stdio(false); cin.tie(0);
	int n, nn;
	cin >> n >> nn;

	for (int i = 0; i < nn; i++) {
		cin >> arr[i];
		arr[i]--;
	}

	int ret = 0;
	int tabIdx = 0;

	for (int i = 0; i < nn; i++) {

		if (use[arr[i]]) continue;	//사용하던 아이템임        
								   
		else if (tabIdx < n) {		//멀티탭 공간이 남음
			tab[tabIdx++] = arr[i];
			use[arr[i]] = true;
			continue;
		}


		ret++; // 위 두가지 경우를 제외하고는 뽑을 수 밖에 없음.

		int port = 0;
		int farDistance = 0;

		//멀티탭에 꽂혀있는 것을 검사
		for (int j = 0; j < n; j++) {
			int distance = 987654321;

			for (int k = i + 1; k < nn; k++) {
				if (tab[j] == arr[k]) {
					distance = k;
					break;
				}
			}

			if (distance > farDistance) { //가장 나중에 쓰이는걸로 업데이트
				port = j;
				farDistance = distance;
			}
		}

		//현재 꽂혀있는 것 중에 가장 먼 아이템을 포트에서 제거
		use[tab[port]] = false;
		use[arr[i]] = true;
		tab[port] = arr[i];
	}

	cout << ret;

	return 0;
}
