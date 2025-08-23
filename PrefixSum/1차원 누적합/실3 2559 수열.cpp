#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int nn; cin >> nn;
        v[i] = v[i - 1] + nn;
    }

    int ans = -100 * n - 1;
    for (int i = k; i <= n; i++)
        ans = max(ans, v[i] - v[i - k]);

    cout << ans;
    
    return 0;
}