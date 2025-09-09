// 1. 문자가 같음: LCS(i-1, j-1) + 1 
// 2. 문자가 다름: max(LCS(i-1, j), LCS(i, j-1))

// 처음 분할정복 접근법(Top-Down)을 코드로 구현하면
int fun(int i, int j)
{
    // base case
    if (i == 0 || j == 0) return 0;

    // 메모이제이션
    if (memo[i][j] != -1) return memo[i][j];

    if (s1[i-1] == s2[j-1])
        return memo[i][j] = fun(i-1, j-1) + 1;
    else
        return memo[i][j] = max(fun(i-1, j), fun(i, j-1));
}

// 이제 부분 문제의 의존성을 직접 그래프로 그려서 파악해보자.
// top-down 방식은 의존성이 겹치는 상황이 많이 발생한다 - 비효율적
// 하지만 bottom-up 방식으로 접근하면, 특히 인접행렬 형태로 i j 순서로 증가하면?


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1005][1005];

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;

    // 타뷸레이션
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }    

    cout << dp[s1.length()][s2.length()];
}