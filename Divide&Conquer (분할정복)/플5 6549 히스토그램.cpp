// 스터디 2주차 재귀&분할정복 복슴겸 + 3주차 투포인터 설명용 문제
// Z처럼 탑다운 방식으로 접근 가능
// 가장 큰 직사각형의 포함여부로 왼쪽절반/오른쪽절반/중간경계선걸침 3가지로 분할 후
// 좌/우 재귀로 접근 + 중앙 투포인터로 탐색

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> h;

long long func(int st, int ed)
{
    // 1. base case
    if (st == ed) return h[st];

    // 2. 분할
    int mid = (st + ed) / 2;

    // 3. 정복 - { st ~ mid }, { mid+1 ~ ed } 왼쪽 절반, 오른쪽 절반 재귀로 탐색
    long long ans = max(func(st, mid), func(mid + 1, ed));

    // 4. 결합 - { min, mid+1 } 겹치는 사각형
    int l = mid;
    int r = mid + 1;
    long long height = min(h[l], h[r]); // 작은게 기준!

    ans = max(ans, height * 2); // 초기 너비는 2이므로 h*2. 여기까지가 가장 넓은 ans

    // l/r 투포인터 (늘리는 방향은 그리디)
    while (st < l || r < ed)
    {
        // r 포인터 증가 가능 && 유리
        if (r < ed && (st == l || h[l - 1] < h[r + 1]))
        {
            r++;
            height = min(height, h[r]);
        }
        // l 포인터 증가 가능 && 유리
        else
        {
            l--;
            height = min(height, h[l]);
        }
        
        ans = max(ans, height * (r - l + 1)); // h * 너비
    }

    return ans;
}

int main()
{
    while (true)
    {
        int n; cin >> n;
        if (n == 0) return 0;

        h.resize(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> h[i];

        cout << func(1, n) << '\n';
    }

    return 0;
}

