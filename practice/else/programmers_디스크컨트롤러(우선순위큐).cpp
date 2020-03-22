#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;


int solution(vector<vector<int>> jobs) {
	int answer = 0, j = 0, time = 0;
	sort(jobs.begin(), jobs.end());
	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//오름차순

	while (j < jobs.size() || !pq.empty()) {  //작업할게 남아있거나 작업이 진행중인동안 

		if (jobs.size() > j && time >= jobs[j][0]) {
			pq.push({ jobs[j][1],jobs[j][0] });
			j++;
			continue;
		}
		if (!pq.empty()) {
			time += pq.top().first;
			answer += time - pq.top().second;
			pq.pop();
		}
		else
			time = jobs[j][0];
	}
	return answer / jobs.size();
}