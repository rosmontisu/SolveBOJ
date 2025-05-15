#include <iostream>
using namespace std;

int arr[10001];

int main()
{
    // 부분 수열의 합이 m이 되는 경우 찾기
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    int ans = 0; 
    int sum = 0;
    
    int st = 1; int ed = 1;
    
    // ed를 for로 돌려보자
    for (ed = 1; ed <= n; ed++) 
    {
        sum += arr[ed];
        // m보다 큼
        while (sum > m && st <= ed) 
        {
            sum -= arr[st];
            st++;
        }
        // 같음
        if (sum == m) 
            ans++;
    }
     
    cout << ans;
    return 0;
}    
