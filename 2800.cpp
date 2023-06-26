#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

string input;
vector<string> ans;
set<string> s;
bool visitArr[200];

vector<int> open, close;

// idx : 몇개의 괄호를 제거할지, cnt : 몇개째를 제거한 재귀인지
void go(int idx, int cnt)
{
    if (idx == open.size())
    {
        // 제거한 괄호가 하나라도 있어야 의미있음
        if (cnt > 0)
        {
            string result = "";
            for (int i = 0; i < input.length(); i++)
            {
                if (visitArr[i])
                {
                    result += input[i];
                }
            }
            s.insert(result);
        }
        return;
    }

    go(idx + 1, cnt);

    visitArr[open[idx]] = false;
    visitArr[close[idx]] = false; // 최종출력에서 visit이 false인부분들은 출력 x
    go(idx + 1, cnt + 1);
    visitArr[open[idx]] = true;
    visitArr[close[idx]] = true;
}

int main()
{
    cin >> input;
    stack<int> st;

    for (int i = 0; i < input.length(); i++)
    {
        visitArr[i] = true;

        if (input[i] == '(')
        {
            st.push(i);
        }
        else if (input[i] == ')')
        {
            int idx = st.top();
            st.pop();

            // 여는괄호, 닫는괄호를 세트로 저장
            open.push_back(idx);
            close.push_back(i);
        }
    }

    go(0, 0);

    for (auto &i : s)
    {
        std::cout << i << endl;
    }
}