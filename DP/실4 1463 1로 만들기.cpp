#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

/*
dp[10] = min(dp[10/3] + 1, dp[10/2] + 1, dp[10-1] + 1)

...

dp[n] = min(dp[n/3] + 1, dp[n/2] + 1, dp[n-1] + 1)
*/

int main(void)
{
	int n; cin >> n;
	// 1씩 빼는 경우로 dp를 초기화
	for (int i = 1; i <= n; i++) 
		dp[i] = i;
		

	// 2부터 n까지 모든 자리를 구합니다

	for (int i = 2; i <= n; i++) 
	{
		// 1. 3으로 나누어 가는 경로
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);

		// 2. 2로 나누어 가는 경로
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);

		// 3. 1씩 빼는 경로
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}

	cout << dp[n] - 1;

}