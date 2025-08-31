#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    vector<bool> isP(n + 1, true);
    isP[0] = false;
    isP[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isP[i])
        {
            for (int j = i * i; j <= n; j += i)
                isP[j] = false;
        }
    }

    vector<int> p;
    for (int i = 2; i <= n; i++)
        if (isP[i]) p.push_back(i);

    int ans = 0;
    int sum = 0;
    int r = 0;
    int cnt = p.size();
    
    for (int l = 0; l < cnt; l++)
    {
        while (r < cnt && sum < n)
        {
            sum += p[r];
            r++;
        }

        if (sum == n) ans++; // 찾음

        sum -= p[l];
    }

    cout << ans;
    return 0;
}