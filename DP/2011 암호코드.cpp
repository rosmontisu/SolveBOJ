#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl "\n"
using namespace std;

int arr[5001];
int dp[5001]; 
// dp[a] = b
// a번째 숫자 까지의 암호의 수 b

string str;
char c;
int main(void)
{
    cin >> str; 
    for (int i = 0; i < str.length(); i++)
    {
        c = str[i];
        arr[i+1] = (int)(c - '0'); // 문자를 정수로 변환 (아스키0==48)
    }
    
    // 0만 입력하면 중단.
    //if (str.length() == 1 && arr[0] == '0')
    //{
    //    cout << 0 << endl;
    //    return 0;
    //}
    
    // 0만 입력하면 중단.
    if (str == "0") 
    {
        cout << 0 << endl;
        return 0;
    }
    

    dp[0] = 1;
    const int mod = 1e6;    // e <- 0의 갯수
    for (int i = 1; i <= str.length(); i++)
    {
        if (0 < arr[i] && arr[i] < 10)                 
        {
            dp[i] = (dp[i] + dp[i-1]) % mod;    // 현재 자리 더하기 1~9 이므로
        }
        
        // 1자리면 10의자리가 없으므로.. 넘깁니다.
        if (i == 1) continue;
        
        int tmp = arr[i] + arr[i - 1] * 10;     // 27 밑으로의 수 검사용 변수
        if (10 <= tmp && tmp <= 26)
        {
            dp[i] = (dp[i] + dp[i-2]) % mod;
        }
    }
    
    cout << dp[str.length()] << endl;
    return 0;
}
