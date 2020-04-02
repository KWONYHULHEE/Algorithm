#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct Shark {
	int x;
	int y;
	int size;
	int eat;
	int time;
};


int n;
int arr[30][30];
int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };
bool check[30][30];
queue <Shark> q;
vector <Shark> v;

bool cmp(Shark a, Shark b) {
    if (a.time <= b.time) {
        if (a.time == b.time) {
            if (a.x <= b.x) {
                if (a.x == b.x) {
                    if (a.y < b.y) {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int main() {

	cin >> n;
	Shark s;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				s = { i,j,2,0,0 };
				arr[i][j] = 0;
			}
		}
	}
	int res = 0;

	while (1) {
		v.clear();
		memset(check, false, sizeof(check));
		q.push(s);
		check[s.x][s.y] = true;

		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int size = q.front().size;
			int eat = q.front().eat;
			int time = q.front().time;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n || check[nx][ny]) continue;

				if (arr[nx][ny] == 0 || arr[nx][ny] == size) {
					check[nx][ny] = true;
					q.push({ nx,ny,size,eat,time + 1 });
				}
				else if (arr[nx][ny] < size) {
					check[nx][ny] = true;
					v.push_back({ nx,ny,size,eat + 1,time + 1 });
				}
			}
		}

		if (v.empty()) break;
		sort(v.begin(), v.end(), cmp);

		if (v[0].eat == v[0].size) {
			v[0].eat = 0;
			v[0].size++;
		}
		arr[v[0].x][v[0].y] = 0;
		res += v[0].time;

		s = { v[0].x,v[0].y,v[0].size,v[0].eat,0};

	}

	
	cout << res;

	return 0;
}