#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> h;

long long func(int st, int ed)
{
    if (st == ed) return h[st];

    // 1. 좌우 분할 후 재귀
    int mid = (st + ed) / 2;
    long long ans = max(func(st, mid), func((mid + 1), ed));


    // 2. 투포인터로 모든 경우 확인
    int l = mid;
    int r = mid + 1;
    
    long long height = min(h[l], h[r]);
    long long width = 2;
    ans = max(ans, height * width);

    while (st < l || r < ed)
    {
        if (r < ed && (st == l || h[l - 1] < h[r + 1])) // l을 못움직이거나, r이 더 유리하거나
        {
            r++;
            height = min(height, h[r]);
        }
        else
        {
            l--;
            height = min(height, h[l]);
        }

        width++;
        ans = max(ans, height * width);
    }

    return ans;
}

int main()
{
    int n; cin >> n;
    h.resize(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    cout << func(0, n - 1);

    return 0;
}

