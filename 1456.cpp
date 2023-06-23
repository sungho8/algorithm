#include <iostream>
#include <map>
// 10^14 의 거듭제곱인 10^7까지만 필요
#define MAX 10000001

using namespace std;

long long p[MAX];

// 에라토스테네스의 채
void primeNumber()
{
    for (int i = 0; i < MAX; i++)
    {
        p[i] = i;
    }

    for (int i = 2; i * i < MAX; i++)
    {
        if (p[i] == 0)
            continue;

        for (int j = i * i; j < MAX; j += i)
            p[j] = 0;
    }
}

int main()
{
    long long A, B, ans = 0;
    cin >> A >> B;

    primeNumber();

    for (int i = 2; i < MAX; i++)
    {
        if (p[i] == 0)
            continue;
        long long cur = i * i;
        while (cur <= B)
        {
            if (cur >= A)
            {
                ans++;
            }
            cur *= i; // 계속해서 거듭제곱을 넣어준다.
        }
    }
    std::cout << ans << endl;
}