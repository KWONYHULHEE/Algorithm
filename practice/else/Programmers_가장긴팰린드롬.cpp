#include <string>
using namespace std;

int longest;
string word; int wordsize;

void oddlengthCheck(int position) { //홀수 길이의 팰린드롬이라 가정했을때 길이 구하기
	int count = 1;
	for (int i = 1; i <= wordsize; i++) {
		if ((position - i < 0) || (position + i >= wordsize))
			break;
		if (word[position - i] == word[position + i])
			count += 2;
		else
			break;
	}
	if (count > longest)
		longest = count;
}
void evenlengthCheck(int position) { //짝수 길이의 팰린드롬이라 가정했을때 길이 구하기
	int count = 0;
	for (int i = 0; i < wordsize; i++) {
		if ((position - i < 0) || (position + i >= wordsize - 1))
			break;
		if (word[position - i] == word[position + i + 1])
			count += 2;
		else
			break;
	}
	if (count > longest)
		longest = count;
}

int solution(string s)
{
	longest = 1;
	word = s;
	wordsize = s.length();
	for (int i = 0; i < s.length(); i++) {
		oddlengthCheck(i);
		evenlengthCheck(i);
	}
	return longest;
}