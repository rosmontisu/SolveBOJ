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
    
    int tmp = ans;
    for (int i = k; i < n; i++)
    {
        tmp -= arr[i-k];
        tmp += arr[i];
        
        if (ans < tmp)
            ans = tmp;
    }
    
    cout << ans;
    return 0;
}