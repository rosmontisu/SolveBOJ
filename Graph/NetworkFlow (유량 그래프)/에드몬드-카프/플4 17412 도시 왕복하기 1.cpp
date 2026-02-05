#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int c[405][405]; // capacity
int f[405][405]; // flow
vector<int> adj[405]; // u -> v

int main()
{
    // 가중치가 1인 최대 유량
    // S(source) : 1
    // T(sink) : 2

    int n, p;
    cin >> n >> p;
    for (int i = 0; i < p; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] += 1; // 경로 1 추가
        // c[v][u] -= 1; 
    }

    int ans = 0;
    while (true)
    {
        vector<int> p(405, -1);
        queue<int> q;

        // 1에서 2로 도착하는 경로 찾기 (BFS)
        const int s = 1;
        const int t = 2;
        q.push(s);
        p[s] = s;
        while (!q.empty())
        {
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur])
            {
                if (p[nxt] != -1) continue; // 이미 방문함
                if (c[cur][nxt] - f[cur][nxt] <= 0) continue; // 유량 한계임

                p[nxt] = cur;
                q.push(nxt);
                if (nxt == t) break;
            }
        }

        // break condition
        if (p[t] == -1) break;

        // amount
        int amount = 0x3f3f3f3f;
        for (int cur = t; cur != s; cur = p[cur])
            amount = min(amount, c[p[cur]][cur] - f[p[cur]][cur]);


        //const int amount = 1;

        // 역추적
        for (int cur = t; cur != s; cur = p[cur])
        {
            int prv = p[cur];

            f[prv][cur] += amount; // u->v
            f[cur][prv] -= amount; // v->u
        }

        ans += 1;
    }

    cout << ans;
}