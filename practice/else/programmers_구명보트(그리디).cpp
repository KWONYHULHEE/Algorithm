/*
1. 정렬을 한다.

2. 제일 무게가 많이 나가는 사람을 태우고 태운사람수를 증가시킨다.

3. 제한무게에 태운사람 무게를빼고 제일 가벼운사람을 태울 수 있는지 확인한다.

4. 태울 수 있다면 태운사람 수를 증가시킨다.

5. 보트를 보내고 보트가 나간횟수를 1 증가시킨다.

6. 끝날때까지 반복하고 결과값을 리턴한다.
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int solution(vector<int> people, int limit) {
	int answer = 0, cnt = 0, begin = 0, end = 1;
	sort(people.begin(), people.end());
	while (1) {
		int first = people[people.size() - end++];
		cnt++;
		if (limit - first >= people[begin]) {
			begin++;
			cnt++;
		}
		answer++;
		if (cnt >= people.size())    break;
	}
	return answer;
}