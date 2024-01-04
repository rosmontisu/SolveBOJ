/*
dp[0] = 0;
dp[1] = 10;
dp[2] = 55;
*/
#include <iostream>
using namespace std;
int dp[1002][11];

#define mod 10007

void solve(int n)
{
    // dp[1][j] 초기화
    // 길이가 1인 오르막 수의 갯수는 항상 1이다
    // 1,0 ~ 1,9
    for (int i = 0; i <= 9; i++)
    {
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= n; i++)
    {
        // 모든 dp에서 첫번째는 0이므로 오름수는 1개이다. 
        dp[i][0] = 1;
        
        // 각 dp마다 0~9의 오름차순을 계산한다.
        for (int j = 0; j <= 9; j++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
        }
    }
    
    // dp[n]의 값은 해당 dp의 0~9의 모든 경우의 수의 합이다.
    int answer = 0; 
    for (int i = 0; i <= 9; i++) 
    {
        answer += dp[n][i];
    }
    cout << answer % mod << endl;   
}

int main(void)
{
    int input;
    cin >> input;
    solve(input);
    
    return 0;
}

