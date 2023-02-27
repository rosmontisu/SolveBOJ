/*
1. 잔을 선택하면 비워야한다.
2. 연속 3잔을 모두 마실수는 없다.

마지막 (n) 잔을 마셨을때 경우의 수

1. n-1 잔을 안마신 경우
>> [n] + [n-2]
2. n-1 잔을 마신 경우
>> [n] + [n-1] + [n-3]
예외. 2잔 연속으로 먹지 않은 경우가 더 큰 경우 확인
>> max([n] , [n-1])

case1)
o x x
x o x
o o x
x x x
위 경우의 최대는 oox 이다. 
즉 x번째 까지 마시는 최대의 값은 
x-1까지의 합이다. 

case2)
x o o
o x o
x x o
위 경우의 최대는 xoo 또는 oxo 이다.
즉 o번 까지 마시는 최대의 값은
o-3까지 마신 양 + o-1 + o 또는 o-2 + o 이다.
-----------------------------------------
위의 경우에서 max를 구하면 된다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001];
int input[10001];

int main(void)
{   
    int n;  cin >> n;
    
    for (int i = 1; i <= n; i++)
        cin >> input[i];
    
    dp[1] = input[1];           // oo
    dp[2] = dp[1] + input[2];   // oo
    
    
    for (int i = 3; i <= n; i++)
    {
        // (???o)xoo || (???)oxo 중에서 max를 구한다.
        dp[i] = max(dp[i-3] + input[i-1] + input[i], dp[i-2] + input[i]);
        // (????)?ox || (????)xoo 혹은 oxo ((위에서 가져온 dp))
        // 지금 만든 dp와 이번 포도주를 먹지 않는 dp중 더 큰 값을 적용한다.
        dp[i] = max(dp[i-1], dp[i]); 
    }
    cout << dp[n] << endl;
    
    return 0;
}
