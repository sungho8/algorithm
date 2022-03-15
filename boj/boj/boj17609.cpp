#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int IsPalindrome(int Left, int Right, int Delete, string Str)
{
	while (Left < Right)
	{
		if (Str[Left] != Str[Right])
		{
			if (Delete == 0)
			{
				if (IsPalindrome(Left + 1, Right, 1, Str) == 0 || IsPalindrome(Left, Right - 1, 1, Str) == 0) return 1;
				return 2;
			}
			else return 2;
		}
		else
		{
			Left++;
			Right--;
		}
	}
	return 0;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cout << IsPalindrome(0, s.length() - 1, 0, s) << endl;
	}
}