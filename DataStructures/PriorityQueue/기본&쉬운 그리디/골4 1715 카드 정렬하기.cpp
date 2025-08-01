#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    // 초기에 합친건 계속 합치는데 사용 (A, B, C) -> (A+B) -> (A+B)+C -> A+B가 반복되어 사용됨
    // 가능한 작은합에서 큰합으로 증가해야함 - min heap

    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        int x; 
        cin >> x;
        pq.push(x);
    }

    int ans = 0;
    while (pq.size() != 1)
    {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        ans += (a + b);
        pq.push(a+b);
    }

    cout << ans;

    return 0;
}