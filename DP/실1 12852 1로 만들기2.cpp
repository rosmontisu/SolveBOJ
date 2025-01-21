#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];
int path[1000001];

/*
dp[10] = min(dp[10/3] + 1, dp[10/2] + 1, dp[10-1] + 1)

...

dp[n] = min(dp[n/3] + 1, dp[n/2] + 1, dp[n-1] + 1)
*/

int main(void)
{
	int n; cin >> n;

	dp[1] = 1;

	// 1씩 빼는 경우로 dp를 초기화
	for (int i = 2; i <= n; i++)
	{
		dp[i] = i;
		path[i] = i - 1; // 한칸 뒤로 가면 경로
	}
		

	// 2부터 n까지 모든 자리를 구합니다

	for (int i = 2; i <= n; i++) 
	{
		// 1. 3으로 나누어 가는 경로
		if (i % 3 == 0)
		{
			if (dp[i] > dp[i / 3] + 1)
			{
				dp[i] = dp[i / 3] + 1; // /3 했을때의 값에서 +1
				path[i] = i / 3; // 현재 자리에서 /3
			}
		}

		// 2. 2로 나누어 가는 경로
		if (i % 2 == 0)
		{
			if (dp[i] > dp[i / 2] + 1)
			{
				dp[i] = dp[i / 2] + 1; // /2 했을때의 값에서 +1
				path[i] = i / 2; // 현재 자리에서 /2
			}
		}

		if (dp[i] > dp[i - 1] + 1)
		{
			dp[i] = dp[i - 1] + 1;
			path[i] = i - 1; // 현재 자리에서 1칸 뒤로
		}
	}

	cout << dp[n] - 1 << '\n';

	cout << n << ' '; // 현재 자리에서 부터 시작
	while (n >= 1)
	{
		if (n == 1)
			break;
		cout << path[n] << ' ';
		n = path[n];
	}
}