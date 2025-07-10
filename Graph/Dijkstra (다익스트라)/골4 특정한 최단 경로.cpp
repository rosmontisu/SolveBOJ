// 1 -> u -> v -> N 경로
// 1 -> v -> u -> N 경로 
//2가지 경로를 구한 후 더 짧은 경로 선택

// 어떻게?
// 1번 최단거리
// u 최단 거리
// v 최단 거리
// 위 3개를 구한 후, 합치면 된다


#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<pair<int, int>> adj[1000]; // w,v [u]
int dist[1000];

void dijkstra(int st)
{
    fill(dist, dist+n+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[st] = 0;
    pq.push({ 0, st });
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if (dist[cur.second] != cur.first) continue; // 값이 다름
        
        for (auto nxt : adj[cur.second])
        {
            if (dist[nxt.second] <= dist[cur.second]+nxt.first) continue;
            dist[nxt.second] = dist[cur.second]+nxt.first;
            pq.push({ dist[nxt.second], nxt.second });
        }
    }
}

int main()
{
    int n, e; cin >> n >> e;
    for (int i = 1; i <= e; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ c, b });
        adj[b].push_back({ c, a });
    }
    
    // 꼭 거쳐야하는 임의의 정점
    int u, v;
    cin >> u >> v;
    
    // 1 -> u / 1 -> v
    dijkstra(1);
    long long st2u = dist[u];
    long long st2v = dist[v];
    
    // u -> v / u -> n (ed)
    dijkstra(u);
    long long u2v = dist[v];
    long long u2ed = dist[n];
    
    // v -> u (양방향이라 u2v랑 같음) / v -> n (ed)
    dijkstra(v);
    long long v2u = dist[u]; 
    long long v2ed = dist[n];
    
    // 1(st) -> u -> v -> n(ed)
    // 1(st) -> v -> u -> n(ed)
    long long p1 = st2u + u2v + v2ed;
    long long p2 = st2v + v2u + u2ed;
    
    long long ans = min(p1, p2);
    
    if (ans >= INF)
        cout << -1;
    else
        cout << ans;
    
    return 0;
}
