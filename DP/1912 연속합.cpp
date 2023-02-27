#include <iostream>
#include <algorithm>
using namespace std;

int input[100001];
int dp[1000001];

int main(void)
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> input[i];

    int answer = input[1];  // 정답값에 시작값 넣어주기
    dp[1] = input[1];       //dp를 시작값으로

    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i - 1] + input[i], input[i]); // 지금까지의 합 vs 새로운 합
        answer = max(dp[i], answer); // 새로만들어진 합 vs 지금까지의 정답
    }

    cout << answer << endl;
    return 0;
}

