#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int ans = -1;
string A, B;

int main()
{
    cin >> A >> B;

    sort(A.begin(), A.end()); // next_permutation을 할때는 무조건 sort가 먼저 와야한다.
    do
    {
        if (A[0] == '0')
            continue;
        if (stoi(A) < stoi(B))
            ans = max(ans, stoi(A));
    } while (next_permutation(A.begin(), A.end()));
    std::cout << ans << endl;
}