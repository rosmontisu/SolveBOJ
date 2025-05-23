#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<pair<int, int>> adj[1002];
int n, m, x;

int dijkstra(int st, int ed)
{
    vector<int> dist(n + 1, INF);
    dist[st] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ dist[st], st });

    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        int now_dist = cur.first; 
        int now_vertex = cur.second; 

        if (dist[now_vertex] != now_dist) continue;
        
        // 이쪽 변수명을 now -> nxt가 아니라 bfs때처럼 w -> dw 로 바꾸는것도 고려할만
        for (auto nxt : adj[now_vertex])
        {
            int nxt_dist = nxt.first;
            int nxt_vertex = nxt.second;

            if (dist[nxt_vertex] > now_dist + nxt_dist)
            {
                dist[nxt_vertex] = now_dist + nxt_dist;
                pq.push({ dist[nxt_vertex], nxt_vertex });
            }
        }
    }

    return dist[ed]; // st에서 ed로의 거리 반환
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({ w, v });
    }

    int ans = 0;

    for (int st = 1; st <= n; st++)
        ans = max(ans, dijkstra(st, x) + dijkstra(x, st));

    cout << ans;
}