#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> adj[10005];
int c[10005][10005];
int f[10005][10005];

int main()
{
    int n, p; // 도시, 길
    cin >> n >> p;

    // 1 -> 2 & 2 -> 1 횟수

    for (int i = 0; i < p; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // 음수용

        c[u][v] += 1;
    }

    int ans = 0; 
    while (true)
    {
        queue<int> q;
        vector<int> p(10005, -1);
        int s, t;
        s = 1;
        t = 2;
        p[s] = s;
        q.push(s);
        // 1. 경로 찾기
        while (!q.empty())
        {
            
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur])
            {
                if (c[cur][nxt] - f[cur][nxt] <= 0) continue; 
                if (p[nxt] == cur) continue;

                p[nxt] = cur;
                q.push(nxt);

                if (nxt == t) break;
            }
        }

        if (p[t] == -1) break;

        // 2. amount
        int amount = 0x3f3f3f3f;
        for (int cur = t; p[cur] != s; cur = p[cur])
            amount = min(amount, c[p[cur]][cur] - f[p[cur]][cur]);

        // 3. 역추적
        for (int cur = t; p[cur] != s; cur = p[cur])
        {
            f[p[cur]][cur] += amount;
            f[cur][p[cur]] -= amount;
        }

        ans += 1;
    }

    cout << ans;

}