#include<iostream>
using namespace std;

int arr[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int ans = 0;
    for (int i = 0; i < k; i++)
        ans += arr[i];
    
    int cnt = ans;
    for (int i = 0; i < n-k; i++)
    {
        cnt -= arr[i];
        cnt += arr[i+k];
        
        if (cnt > ans) ans = cnt;
    }
    
    cout << ans;
    return 0;
}