/*
1.  x%3 == 0 이면 x/3
2.  x%2 == 0 이면 x/2
3.  else 이면 x--

위 3개의 연산을 최소로 사용해서 1로 만들어라
*/
#include <iostream>
#include <algorithm>

using namespace std;
int dp[1000000];

int main(void)
{
    int n;
    cin >> n;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;

        if (i % 3 == 0)
        {
            //  -1 과 /3 비교합니다.
            dp[i] = min(dp[i - 1] + 1, dp[i / 3] + 1);
        }
        if (i % 2 == 0)
        {
            //  이전 dp와 /2 비교합니다.
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }

        // dp가 비어 있다면 그냥 -1
        // dp가 들어 있다면 /3 /2 -1중 가장 작은 수
        
    }

    cout << dp[n];
    return 0;
}