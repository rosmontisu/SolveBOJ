#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int dist[1005];
vector<pair<int, int>> adj[1005]; // { 가중치, 정점 }
const int INF = 0x3f3f3f3f;

int main()
{
    int v, e;
    cin >> v;
    cin >> e;
    fill(dist, dist+v+1, INF);
    
    
    while(e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w, v });
    }

    int st, ed;
    cin >> st >> ed;


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[st] = 0;
    
    pq.push({ 0, st });
    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();

        if (dist[cur.second] != cur.first) continue; // q.v의 dist != q.dist
        for (auto nxt : adj[cur.second])
        {
            if (dist[nxt.second] <= dist[cur.second] + nxt.first) continue; // q.v의 dist <= q.dist + q.nxt
            dist[nxt.second] = dist[cur.second] + nxt.first;
            pq.push({ dist[nxt.second], nxt.second });
        }
    }

    cout << dist[ed] << '\n'; // 최단거리
    return 0;
}