#include <iostream>
using namespace std;
int dp[10007];

int main()
{
    int n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;

    // dp3 = dp2 + dp1 + dp1
    // dp4 = dp3 + dp2 + dp2

    // 현재 dp번째 도형이 세로라고 가정했을때의 경우의 수와
    // 현재 dp번째 도형이 가로라고 가정했을때의 경우의 수를
    // 생각해보면 쉽게 풀린다.

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 2]) % 10007;
    }

    cout << dp[n];
    return 0;
}
