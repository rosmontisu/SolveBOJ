#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main()
{
    int n, s;
    cin >> n >> s;
    
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    int st = 1;
    int ed = 1;
    int ans = n+1;
    int sum = arr[1];
    while(st <= ed && ed <= n)
    {
        
        if (sum < s)
            sum += arr[++ed]; // 기준값 S에 도달 못함.
        else
        {
            ans = min(ans, ed-st+1); // ed-st+1이 현재 길이
            sum -= arr[st++]; // 기준값 S에 도달. 
            
        }
    }
    
    if (ans == n+1)
        cout << 0;
    else
        cout << ans;
    
    return 0;
}