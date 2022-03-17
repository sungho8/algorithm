#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 101

using namespace std;

int R, C, K, Answer;
int MAP[MAX][MAX];
int Number_Cnt[MAX];

void Find()
{
	int Time = 0;
	int Hang = 3;
	int Yul = 3;

	while (1)
	{
		if (MAP[R][C] == K) { Answer = Time; break; }
		if (Time > 100) { Answer = -1; break; }

		vector<int> Size;
		if (Hang >= Yul)    // ���簢���̰ų� ���ηα� ����
		{
			for (int i = 1; i <= Hang; i++)
			{
				vector<pair<int, int>> V;
				memset(Number_Cnt, 0, sizeof(Number_Cnt));
				for (int j = 1; j <= Yul; j++) Number_Cnt[MAP[i][j]]++;
				for (int j = 1; j < MAX; j++)
				{
					if (Number_Cnt[j] == 0) continue;
					V.push_back(make_pair(Number_Cnt[j], j));
				}
				sort(V.begin(), V.end());
				for (int j = 1; j <= Yul; j++) MAP[i][j] = 0;
				int Idx = 1;
				for (int j = 0; j < V.size(); j++)
				{
					MAP[i][Idx++] = V[j].second;
					MAP[i][Idx++] = V[j].first;
				}
				Idx--;
				Size.push_back(Idx);
			}
			sort(Size.begin(), Size.end());
			Yul = Size.back();
		}
		else        // ���η� �� ���
		{
			for (int i = 1; i <= Yul; i++)
			{
				vector<pair<int, int>> V;
				memset(Number_Cnt, 0, sizeof(Number_Cnt));
				for (int j = 1; j <= Hang; j++) Number_Cnt[MAP[j][i]]++;
				for (int j = 1; j < MAX; j++)
				{
					if (Number_Cnt[j] != 0)
					{
						V.push_back(make_pair(Number_Cnt[j], j));
					}
				}
				sort(V.begin(), V.end());
				for (int j = 1; j <= Hang; j++) MAP[j][i] = 0;
				int Idx = 1;
				for (int j = 0; j < V.size(); j++)
				{
					MAP[Idx++][i] = V[j].second;
					MAP[Idx++][i] = V[j].first;
				}
				Idx--;
				Size.push_back(Idx);
			}
			sort(Size.begin(), Size.end());
			Hang = Size.back();
		}
		Time++;
	}
}

int main()
{
	cin >> R >> C >> K;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> MAP[i][j];
		}
	}

	if (MAP[R][C] == K)
	{
		Answer = 0;
		cout << Answer << endl;
		return 0;
	}
	Find();
	cout << Answer << endl;
}