#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, answer;

//void print(vector<vector<long long>> map) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << map[i][j] << " ";
//		}
//		cout << endl;
//	}
//}

// ���� �̵�
vector<vector<long long>> left(vector<vector<long long>> map) {
	vector<vector<bool>> check(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (map[i][j] == 0)
				continue;
			for (int k = j - 1; k >= 0; k--) {
				// ���� ���ڸ� �����ٸ� 2�� , �� �̹� ������ ��ġ��� ����
				if (map[i][k] == map[i][k + 1] && !check[i][k]) {
					map[i][k] *= 2;
					map[i][k + 1] = 0;
					check[i][k] = true;
					break;
				}
				// ����ִ� ĭ�̶�� ��ĭ���� �̵�
				else if (map[i][k] == 0) {
					map[i][k] = map[i][k + 1];
					map[i][k + 1] = 0;
				}
				else {
					break;
				}
			}
		}
	}
	return map;
}

// ������ �̵�
// o o x
// o o x
// o o x
vector<vector<long long>> right(vector<vector<long long>> map) {
	vector<vector<bool>> check(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (map[i][j] == 0)
				continue;
			for (int k = j + 1; k < n; k++) {
				// ���� ���ڸ� �����ٸ� 2�� , �� �̹� ������ ��ġ��� ����
				if (map[i][k] == map[i][k - 1] && !check[i][k]) {
					map[i][k] *= 2;
					map[i][k - 1] = 0;
					check[i][k] = true;
					break;
				}
				// ����ִ� ĭ�̶�� ��ĭ���� �̵�
				else if (map[i][k] == 0) {
					map[i][k] = map[i][k - 1];
					map[i][k - 1] = 0;
				}
				else {
					break;
				}
			}
		}
	}
	return map;
}

// �Ʒ� �̵�
// o o o
// o o o
// x x x
vector<vector<long long>> down(vector<vector<long long>> map) {
	vector<vector<bool>> check(n, vector<bool>(n, false));

	for (int j = 0; j < n; j++) {
		for (int i = n - 2; i >= 0; i--) {
			if (map[i][j] == 0)
				continue;
			for (int k = i + 1; k < n; k++) {
				// ���� ���ڸ� �����ٸ� 2�� , �� �̹� ������ ��ġ��� ����
				if (map[k][j] == map[k - 1][j] && !check[k][j]) {
					map[k][j] *= 2;
					map[k - 1][j] = 0;
					check[k][j] = true;
					break;
				}
				// ����ִ� ĭ�̶�� ��ĭ���� �̵�
				else if (map[k][j] == 0) {
					map[k][j] = map[k - 1][j];
					map[k - 1][j] = 0;
				}
				else {
					break;
				}
			}
		}
	}
	return map;
}

// ���� �̵�
// x x x
// o o o
// o o o
vector<vector<long long>> up(vector<vector<long long>> map) {
	vector<vector<bool>> check(n, vector<bool>(n, false));

	for (int j = 0; j < n; j++) {
		for (int i = 1; i < n; i++) {
			if (map[i][j] == 0)
				continue;
			for (int k = i - 1; k >= 0; k--) {
				// ���� ���ڸ� �����ٸ� 2�� , �� �̹� ������ ��ġ��� ����
				if (map[k][j] == map[k + 1][j] && !check[k][j]) {
					map[k][j] *= 2;
					map[k + 1][j] = 0;
					check[k][j] = true;
					break;
				}
				// ����ִ� ĭ�̶�� ��ĭ���� �̵�
				else if (map[k][j] == 0) {
					map[k][j] = map[k + 1][j];
					map[k + 1][j] = 0;
				}
				else {
					break;
				}
			}
		}
	}
	return map;
}

void dfs(int depth, vector<vector<long long>> map) {
	if (depth == 5) {
		int max = 0;
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map.size(); j++) {
				max = map[i][j] > max ? map[i][j] : max;
			}
		}
		answer = answer > max ? answer : max;
		return;
	}

	dfs(depth + 1, up(map));
	dfs(depth + 1, down(map));
	dfs(depth + 1, left(map));
	dfs(depth + 1, right(map));
}

int main()
{
	cin >> n;

	vector<vector<long long>> map;
	for (int i = 0; i < n; i++) {
		vector<long long> v;
		for (int j = 0; j < n; j++) {
			long long num;	cin >> num;
			v.push_back(num);
		}
		map.push_back(v);
	}

	dfs(0, map);
	cout << answer;
}