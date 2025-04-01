#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    
    if (n == 0) cout << 0;
    
    else 
    {
        // 이진로그
        // 2^x=n  <-> Log2(N)
        
        // log2(n) 계산
        // 소수점이 0보다 크면 무조건 마법 1회가 더 필요하고
        ll ans = ceil(log2(n)); 
        
        // 초기상태 0 -> 1 로 만드는 마법 1회가 더 필요
        cout << ans + 1;
    }
    
    return 0;
}