/*
	 �� �簢���� ���� - (���α��� + ���α��� - �ִ�����)

*/



using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

long long solution(int w, int h)
{
	long long answer = 1;
	long long sum = (long long)w * (long long)h;
	answer = sum - (w + h - gcd(w, h));
	return answer;
}