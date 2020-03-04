#include<iostream>
#include<queue>
using namespace std;
const int INF = 987654321;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main()
{

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        int map[101][101] = { 0, };
        int dist[101][101] = { 0, };
        int n;
        cin >> n;
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                scanf("%d", &map[i][j]);
                dist[i][j] = INF;
            }
        }
 
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> q;
		//오름차순
        dist[0][0] = 0;
        q.push({ dist[0][0],{ 0,0 } });
 
        while (!q.empty())
        {
            int cost = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
 
            if (cost>dist[x][y])
            {
                continue;
            }
 
            for (int d = 0; d<4; d++)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];
                int w = map[nx][ny];
                if (nx >= 0 && ny >= 0 && nx<n && ny<n)
                {
                    if (dist[nx][ny]>cost + w)
                    {
                        dist[nx][ny] = cost + w;
                        q.push({ dist[nx][ny],{ nx,ny } });
                    }
                }
            }
        }
 
        cout << "#" << t << " " << dist[n - 1][n - 1] << "\n";
 
    }
 
    return 0;
}