#include <iostream>
using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    
    ll cat = 1;
    ll ans = 1;
    
    while(cat < n)
    {
        cat *= 2;
        ans++;
    }
    
    if (n == 0) cout << 0;
    else cout << ans;
    
    return 0;
}