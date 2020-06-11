#include <iostream>
#include <string>
#include <queue>
#include <functional>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int MAX = 100010;
const int INF = 987654321;

vector<pair<int, int>> v[MAX];
map<string, int> m;
int dist[MAX];
int N, M, q;
string s, e;
int c;

void dijkstra() {

   priority_queue<pair<int, int>> pq;

   int start = m.find(s)->second;
   int end = m.find(e)->second;

   pq.push({ 0, start });
   dist[start] = 0;

   while (!pq.empty()) {

      int cost = pq.top().first;
      int cur = pq.top().second;
      pq.pop();

      if (dist[cur] < cost)   continue;

      for (int i = 0; i < v[cur].size(); i++) {
         int next = v[cur][i].first;
         int ncost = cost + v[cur][i].second;

         if (dist[next] > ncost) {
            dist[next] = ncost;
            pq.push({ ncost, next });
         }
      }
   }

   if (dist[end] == INF) cout << "-1\n";
   else cout << dist[end] << "\n";
}

int main()
{

   cin >> N >> M;

   int index = 0;
   for (int i = 0; i < M; i++) {
      cin >> s >> e >> c;

      if (m.count(s) == 0) m[s] = index++;
      if (m.count(e) == 0) m[e] = index++;

      int a = m.find(s)->second;
      int b = m.find(e)->second;

      v[a].push_back({ b, c });
   }

   cin >> q;

   for (int i = 0; i < q; i++) {

      fill(dist, dist + MAX, INF);
      cin >> s >> e;

      if (s == e) cout << "0\n";
      else if (m.count(s) == 0 || m.count(e) == 0) cout << "-1\n";
      else dijkstra();

   }

   return 0;
}