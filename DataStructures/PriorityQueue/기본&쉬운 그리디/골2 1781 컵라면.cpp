#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
    // 1. 가장 데드라인이 임박한걸 먼저 해야하고
    // 2. 그 중에서도 가장 라면을 많이 주는걸 해야한다.
    // 하지만, 위와 같은 접근일때 pq안에서 min/max 상반되게 정렬은 불가하므로(STL기준)
    // 먼저 데드라인 기준 정렬을하고, min heap에 넣다가 데드라인 초과때마다 다시 정산하면된다.
    // -> 저번 2025 07 pccp때 못풀었던던 2번문제랑 비슷한 유형

    int n; cin >> n;
    vector<pair<int, int>> vec(n);

    // { 데드라인, 라면 }
    for (int i = 0; i < n; i++)
        cin >> vec[i].first >> vec[i].second;

    sort(vec.begin(), vec.end());

    priority_queue<int, vector<int>, greater<int>> pq; // min heap

    for (int i = 0; i < n; i++)
    {
        int a = vec[i].first;
        int b = vec[i].second;

        pq.push(b);
        if (pq.size() > a) pq.pop(); // 풀려는 문제 수(pq.size)가 데드라인 초과시, 가장 적은 보상문제 제거
    }

    int ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}