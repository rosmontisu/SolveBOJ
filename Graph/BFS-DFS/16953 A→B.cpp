#include <iostream>
#include <queue>
using namespace std;

long long Bfs(long long a, long long b)
{
    // 현재 수, 연산 횟수가 필요
    // 현재 수 <= b
    // 만약 b를 넘어가면 break
    // 모든 루프가 실패하면 return -1;
    queue<pair<long long, long long>> q;
    q.push({ a, 1 }); // (현재숫자, 연산횟수)

    while (!q.empty())
    {
        pair<long long, long long> cur = q.front(); q.pop();
        long long nowA1 = cur.first * 2;
        long long nowA2 = cur.first * 10 + 1;
        long long nowCount = cur.second + 1;

        if (nowA1 == b) return nowCount;
        if (nowA2 == b) return nowCount;

        if (nowA1 < b)
            q.push({ nowA1, nowCount });
        if (nowA2 < b)
            q.push({ nowA2, nowCount });
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long a, b;
    cin >> a >> b;
    cout << Bfs(a, b);
    return 0;
}