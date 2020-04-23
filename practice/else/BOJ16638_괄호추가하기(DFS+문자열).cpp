#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

const int MAX = 20;

int N;
char MAP[MAX];
bool Gwal_Ho[MAX];
long long Answer = -987654321987654321;


long long Actual_Calculate(long long N1, long long N2, string B)
{
	if (B == "+") return N1 + N2;
	else if (B == "-") return N1 - N2;
	else if (B == "*") return N1 * N2;
}

long long Calculate()
{
	vector<string> V;
	for (int i = 0; i < N;)
	{
		if (!Gwal_Ho[i])
		{
			string S = "";
			S = MAP[i];
			V.push_back(S);
			i++;
		}
		else  //��ȣ���
		{
			string S = "";
			S += MAP[i];
			long long Temp = stoi(S); //������

			S = "";
			S = S + MAP[i + 2];
			long long Temp2 = stoi(S); //��������

			S = "";
			S = S + MAP[i + 1];
			string B_Temp = S; //����Һ�ȣ

			long long Temp_Ans = Actual_Calculate(Temp, Temp2, B_Temp); //��ȣ��������ؼ�
			string S_Temp_Ans = to_string(Temp_Ans);
			V.push_back(S_Temp_Ans); //��갪�� �־��� 
			i = i + 3;
		}
	}

	vector<string> NV;
	for (int i = 0; i < V.size(); )
	{
		if (V[i] == "*")
		{
			long long Temp = stoi(NV[NV.size() - 1]); //�������� �� ���̶�
			long long Temp2 = stoi(V[i + 1]); // ���� * �ڿ��ִ� ���̶�
			long long Temp_Ans = Actual_Calculate(Temp, Temp2, V[i]); //���ؼ�
			string S_Temp_Ans = to_string(Temp_Ans); // ���̳ʽ����� ���ü������� char�ȵǰ� string�ؾߵ�
			NV.pop_back(); //�������� ���ְ�
			NV.push_back(S_Temp_Ans); //���Ѱ� �־���
			i += 2;
		}
		else
		{
			NV.push_back(V[i]);
			i++;
		}
	}
	//�������
	long long R_Value = (long long)(stoi(NV[0]));
	for (int i = 1; i < NV.size(); i = i + 2)
	{
		if (NV[i] == "+") R_Value += stoi(NV[i + 1]);
		else if (NV[i] == "-") R_Value -= stoi(NV[i + 1]);
	}

	return R_Value;
}

void DFS(int Idx)
{
	if (Idx >= N)
	{
		Answer = max(Answer, Calculate());
		return;
	}

	for (int i = Idx; i < N; i = i + 2)
	{
		if (i + 2 < N)
		{
			if (!Gwal_Ho[i] && !Gwal_Ho[i + 2])
			{
				Gwal_Ho[i] = true;
				Gwal_Ho[i + 2] = true;
				DFS(Idx + 2);
				Gwal_Ho[i] = false;
				Gwal_Ho[i + 2] = false;
			}
		}
		else
		{
			DFS(i + 1);
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> MAP;

	DFS(0);
	cout << Answer << endl;

	return 0;
}


