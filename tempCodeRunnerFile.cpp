#include <iostream>
#include <queue>

using namespace std;

int N, M;

int arr[101][101];
bool visitA[101][101];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;

        for (int j = 1; j <= s.length(); j++)
        {
            arr[i][j] = s[j - 1] - '0';
        }
    }

    // for (int i = 0; i <= N + 1; i++)
    // {
    //     for (int j = 0; j <= M + 1; j++)
    //     {
    //         std::cout << arr[i][j];
    //     }
    //     std::cout << endl;
    // }
    std::cout << 1 << endl;
    queue<pair<pair<int, int>, int>> q;
    q.push({{1, 1}, 1});
    visitA[1][1] = true;

    while (!q.empty())
    {
        pair<pair<int, int>, int> cur = q.front();
        int y = cur.first.second;
        int x = cur.first.first;
        int dep = cur.second;
        q.pop();

        // std::cout << x << "," << y << " = " << dep << endl;

        if (y == N && x == M)
        {
            std::cout << dep << endl;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (arr[ny][nx] == 1 && !visitA[ny][nx])
            {
                q.push({{nx, ny}, dep + 1});
                visitA[ny][nx] = true;
            }
        }
    }
}