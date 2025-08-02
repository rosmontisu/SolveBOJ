#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i].first >> vec[i].second;

    sort(vec.begin(), vec.end());

    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    for (int i = 0; i < n; i++)
    {
        int a = vec[i].first;   // 날
        int b = vec[i].second;  // 점수

        pq.push(b);
        if (pq.size() > a) pq.pop();
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