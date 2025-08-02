// - pq안쓰고 O(n)으로 처리 가능한 알고리즘, 필요없는 값은 버린다는 아이디어 
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    deque<pair<int, int>> dq; // { v, idx }

    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;

        // 가장 앞 값의 idx가 윈도우 범위를 나감 (앞쪽에서 제거)
        if (!dq.empty())
        {
            if (dq.front().second <= i - l) 
                dq.pop_front();
        }

        // 새로 들어오는 a보다 큰 값은 무조건 탈락 (뒤쪽에서 모두 제거)
        while (!dq.empty() && dq.back().first >= a)
            dq.pop_back();

        dq.push_back({ a, i });

        cout << dq.front().first << ' ';
    }

    return 0;
}