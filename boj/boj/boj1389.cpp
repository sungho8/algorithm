#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> fVec[101];
int fArr[101][101];
queue<int> q;

void bfs(int start) {
	bool v[101] = { false, };
	q.push(start);
	v[start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < fVec[cur].size(); i++) {
			int next = fVec[cur][i];
			// 미방문 친구라면
			if (!v[next]) {
				v[next] = true;
				q.push(next);
				fArr[next][start] = fArr[cur][start] + 1;
				fArr[start][next] = fArr[start][cur] + 1;
			}
		}
	}

}

int main() {
	int N, M;
	int sum = 0, result = 0, min = 1e9;
	cin >> N >> M;


	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		fVec[n1].push_back(n2);
		fVec[n2].push_back(n1);
	}

	// 전부다 bfs를 돌린다
	for (int i = 1; i <= N; i++)
		bfs(i);

	for (int i = 1; i <= N; i++) {
		sum = 0;
		for (int j = 1; j <= N; j++) {
			sum += fArr[i][j];
		}
		if (min > sum) {
			min = sum;
			result = i;
		}
	}

	cout << result;
}