#include <iostream>

using namespace std;

int dp[5001]; // global 이므로 배열이 0으로 초기화된다.

int main(void)
{
	int n;
	cin >> n;

	// dp[n]은 n 키로그램을 의미한다.
	// 3과 5kg은 무조건 1봉지이므로
	// dp[3] 과 dp[5]는 무조건 1이다.
	dp[3] = 1;
	dp[5] = 1;

	// 4 kg은 불가능 하므로 건너뛴다.
	// 6 kg그램부터 nkg까지 계산해준다.
	for (int i = 6; i <= n; i++)
	{
		//dp[i-3] 이 존재
		if (dp[i - 3])
			dp[i] = dp[i - 3] + 1;
		//dp[i-5] 가 존재 하면?
		//현재 dp[i]에 값이 있는지 확인후 넣습니다.
		if (dp[i - 5])
			dp[i] = dp[i] ? min(dp[i], dp[i - 5] + 1) : dp[i - 5] + 1;		
	}

	cout << (dp[n] == 0 ? -1 : dp[n]) << endl;
	return 0;	
}
