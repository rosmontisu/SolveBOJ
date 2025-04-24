#include <iostream>
using namespace std;

long long dp[1000001];
const int DIV_NUM = 1e9+9;

int main()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 7;

    for (int i = 4; i <= 1000000; i++)
    {
        dp[i] = (dp[i-3]%DIV_NUM + dp[i-2]%DIV_NUM + dp[i-1]%DIV_NUM) % DIV_NUM;
    }


    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}