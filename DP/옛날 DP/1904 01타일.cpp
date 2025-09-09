#include <iostream>
using namespace std;
int dp[1000000];

int main()
{
    int N;
    cin >> N;

    // 1 타일과 00타일만 있다.
    // N비트 공간에서 만들 수 있는 모든 2진수의 경우의 수를 구하라
    // 이전에 풀었던 타일링 문제와 매우 흡사하다

    dp[0] = 0;
    dp[1] = 1;  // 1
    dp[2] = 2;  // 00, 11
    // dp[3] = dp[2] + dp[1]; // 100, 111 / 001
    // dp[4] = dp[3] + dp[2]; // 1100, 1111, 1001 / 0000, 0011

    for (int i = 3; i <= N; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }
    

    cout << dp[N];
    return 0;
}
