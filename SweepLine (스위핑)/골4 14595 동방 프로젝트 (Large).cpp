#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    cin >> m;
    if (m == 0)
    {
        cout << n;
        return 0;
    }

    // 전에 그리디 문제랑 비슷한 아이디어로 접그
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }

    int ans = n;
    auto cur = pq.top();
    int st = cur.first;
    int ed = cur.second;
    pq.pop();
    if (pq.empty()) ans -= (ed-st);

    // ans = st; // st 왼쪽은 방이 정상임

    while (!pq.empty())
    {
        auto nxt = pq.top();
        if (nxt.first <= ed)
        {
            // 새로운 시작점이 현재 끝점보다 안쪽에 있으면?
            // 연장된다
            ed = max(ed, nxt.second); // 새로운 끝점이 더 짧을 가능성 고려
            pq.pop();
            if (pq.empty()) ans -= (ed-st);
        }
        else
        {
            // 끊김
            ans -= (ed-st);

            st = nxt.first;
            ed = nxt.second;
            pq.pop();
            if (pq.empty()) ans -= (ed-st);
        }
    }
    cout << ans;
}