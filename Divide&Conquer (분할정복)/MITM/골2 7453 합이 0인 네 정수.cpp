// 4주차 발표용 문제
// 투포인터 결합 유형 - MITM (Meet in the middle)
// o(n^2 log n) = o(n^2) + o(n^2 log n) + o(n^2)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    // 1. MITM. 배열을 2개씩 묶기 O(n^2)
    vector<long long> ab;
    vector<long long> cd;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    }

    // n^2크기 배열을 정렬. O((n^2) log(n^2)) == O(2 * (n^2) log n) -> O(n^2 log n)
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end());

    // 3. 투포인터. 원소의 수가 n*n개니까 O(n^2)
    long long ans = 0;
    int l = 0; 
    int r = cd.size() - 1;
    
    while (l < ab.size() && r >= 0)
    {
        long long sum = ab[l] + cd[r];

        if (sum < 0) l++;
        else if (sum > 0) r--;

        // 0이 되는 경우를 찾음
        else
        {
            long long lcnt = 1;
            long long rcnt = 1;

            // ab에서 중복 값 개수
            while (l + 1 < ab.size() && ab[l] == ab[l + 1])
            {
                lcnt++;
                l++;
            }
            // cd에서 중복 값 개수
            while (r - 1 >= 0 && cd[r] == cd[r - 1])
            {
                rcnt++;
                r--;
            }

            ans += lcnt * rcnt; // 중복되는 숫자들 조합
            l++;
            r--;
        }
    }

    cout << ans;

    return 0;
}