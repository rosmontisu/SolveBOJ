/*

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

이런 삼각형 구조

dp로 구현 가능
위에서 아래로 합치는 식으로 구현해서 [i-1][j] or [i-1][j-1]
가장 아래 줄에서 max값을 출력하면 될듯

배열의 크기는 501
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[501][501];

int main(void)
{
    dp[0][0] = 0;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> dp[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        //왼쪽 끝은 무조건 왼쪽 끝 숫자만 더할 수 있음
        dp[i][1] += dp[i-1][1];
        for (int j = 2; j <= i; j++)
        {
            dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
        }
    }

    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        if(dp[n][i] > max)
            max = dp[n][i];       
    }
    cout << max;
    return 0;
}