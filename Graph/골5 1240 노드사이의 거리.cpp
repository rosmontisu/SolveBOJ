#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> adj[1005];

int main()
{
    int n, m;
    cin >> n >> m;

    while (n--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w, v });
        adj[v].push_back({ w, u });
    }

    while (m--)
    {
        int st, ed;
        cin >> st >> ed;

        vector<int> dist(1005, -1);
        dist[st] = 0;
        queue<int> q;
        q.push(st);
        int ans = 0;
        while (!q.empty())
        {
            int cur = q.front(); q.pop(); // 노드

            for (auto nxt : adj[cur])
            {

            }
        }

        cout << dist[ed] << '\n';
    }

    return 0;
}