/*
r g b 
1번 집과 2번 집은 달라야한다.
n번과 n-1번은 달라야한다.
i번 집은 i-1 i+1 색과 달라야한다.


    R G B
1
2
n-1
n
을 2차원 배열로 생각할때

[2][R] += min([1][G], [1][B])
이다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][3];

int main(void)
{
    int n = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d %d", &dp[i][0], &dp[i][1], &dp[i][2]); 
    }

    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] += min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] += min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] += min(dp[i-1][0], dp[i-1][1]);
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2]});
    cin >> n;
    return 0;
}