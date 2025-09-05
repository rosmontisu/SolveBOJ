// l --> in <-- r
// 양쪽에서 안쪽으로 들어오는 유형 대표 문제 
// 1. 포인터가 2개인 경우
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // monotonic 
    sort(v.begin(), v.end());
    
    // two-pointer
    int l = 0;
    int r = n - 1;
    int ans1 = v[l];
    int ans2 = v[r];
    int sum = abs(ans1 + ans2);
    while (l < r)
    {
        if (sum > abs(v[l] + v[r]))
        {
            sum = abs(v[l] + v[r]);
            ans1 = v[l];
            ans2 = v[r];
        }
        if (v[l] + v[r] > 0) r--;
        else l++;

    }

    cout << ans1 << ' ' << ans2;

    return 0;
}