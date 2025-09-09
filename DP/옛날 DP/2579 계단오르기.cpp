#include <iostream>
using namespace std;

int dp[301];
int arr[301];

int main(void)
{
    dp[0] = 0;
    
    int T; cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> arr[i];
    }
    
    dp[1] = arr[1];            // 1f
    dp[2] = dp[1] + arr[2];    // 2f
    dp[3] = max(arr[1], arr[2]) + arr[3];
    
    for (int i = 4; i <= T; i++)
    {
        dp[i] = max((dp[i-3] + arr[i-1]), dp[i-2]) + arr[i];
    }
    
    cout << dp[T] << endl;
    return 0;
}
