/*
1. ������ �Ѵ�.

2. ���� ���԰� ���� ������ ����� �¿�� �¿������� ������Ų��.

3. ���ѹ��Կ� �¿��� ���Ը����� ���� ���������� �¿� �� �ִ��� Ȯ���Ѵ�.

4. �¿� �� �ִٸ� �¿��� ���� ������Ų��.

5. ��Ʈ�� ������ ��Ʈ�� ����Ƚ���� 1 ������Ų��.

6. ���������� �ݺ��ϰ� ������� �����Ѵ�.
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