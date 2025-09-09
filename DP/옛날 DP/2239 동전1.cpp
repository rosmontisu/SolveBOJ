#include <iostream>
using namespace std;
int dp[10001];
int value[10001];

int main(void)
{
    int n, k; cin >> n >> k;     
    for (int i = 1; i <= n; i++)
        cin >> value[i];   
   
    dp[0] = 1; 
    for (int i = 1; i <= n; i++)
    {
        // 동전의 가치를 시작점으로 한다.
        // ex) 3원짜리 동전은 3원보다 작은 수로 시작할 수 없기때문에..
        for (int j = value[i]; j <= k; j++)
            dp[j] = dp[j] + dp[j - value[i]];    
    }
    cout << dp[k] << endl;
    // dp의 초기식으로 사용하기 위해서
    
    // 0 -> 3 
    // dp[3] += dp[0]
    
    // 6 -> 15
    // dp[16] += dp[6]
    
    //와 같은 트리와 유사한 구조가 성립한다.
    // a -> b
    // dp[b] += dp[a]
    // 로 표기가 가능하다.
    
    // 위와 같은 식의 초기값은 dp[0] 이므로
    // 식이 성립하기 위해서 dp[0] = 1로 초기화 해야한다.

    return 0;
}
