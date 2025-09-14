#include <iostream>
using namespace std;

int dp[105][15];

int main()
{
    /*
    dp[i][j] - [길이][마지막수]
    dp[i][0] = dp[i-1][1]
    dp[i][9] = dp[i-1][8] 
    dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]
    https://cdn.discordapp.com/attachments/1221705740100698112/1416719644579991583/image.png?ex=68c7de7c&is=68c68cfc&hm=50d739b9d84bb8f16712e4ef9d008ab5b48d5b8704fb26d37aeb4f1b0b4b19de&
    */
    int n; cin >> n;

    dp[1][0] = 0;
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    const int DIV = 1000000000;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0) dp[i][j] = dp[i-1][1];
            if (j == 9) dp[i][j] = dp[i-1][8];
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % DIV;
        }
    }

    long long ans = 0;
    for (int i = 0; i <= 9; i++)
        ans += dp[n][i];

    cout << ans % DIV;
    return 0;
}