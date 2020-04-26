/*
	 총 사각형의 갯수 - (가로길이 + 세로길이 - 최대공약수)

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