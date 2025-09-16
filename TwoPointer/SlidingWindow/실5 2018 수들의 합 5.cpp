#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;

    int ans = 0;
    int sum = 0;
    
    int l = 1;
    int r = 1;
    for (r = 1; r <= n; r++)
    {
        sum += r;

        // 루프로 줄이는게 더 깔끔
        while (sum > n)
        {
            sum -= l;
            l++;
        }

        if (sum == n) ans++;
    }

    cout << ans;
}