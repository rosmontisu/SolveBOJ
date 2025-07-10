#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second
using PAIR = pair<int, int>;
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> adj[20005]; // 비용, 정점
int dist[20005]; // 최단 거리 배열

int v, e, st;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> v >> e >> st;

    fill(dist, dist+v+1, INF); // 거리배열 무한으로 초기화

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w, v });
    }

    priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
    dist[st] = 0; // 초기 위치는 거리 0

    // pq순회 시작
    pq.push({ dist[st], st }); // 0, 시작점
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop(); // { 비용, 정점 }
        if (dist[cur.Y] != cur.X) continue; // dist에 거리와 다를 경우 스킾
        for (auto nxt : adj[cur.Y])
        {
            if (dist[nxt.Y] <= dist[cur.Y]+nxt.X) continue; 
            
            // current값을 거치는게 더 빠르면, dist배열 수정, pq에 추가
            dist[nxt.Y] = dist[cur.Y]+nxt.X;
            pq.push({ dist[nxt.Y], nxt.Y });
        }
    }

    for (int i = 1; i <= v; i++)
    {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}