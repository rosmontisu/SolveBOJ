#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> adj[20005]; // { 가중치, 정점 }
const int INF = 0x3f3f3f3f;
int dist[20005];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e, st;
    
    // 1. 초기화 
    cin >> v;
    cin >> e;
    cin >> st;
    fill(dist, dist+v+1, INF);
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w; // u->v | w
        adj[u].push_back({ w, v });
    }
    
    // min 우선순위 큐 (오름차순으로 정렬되어 작은 값이 먼저 나옴)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[st] = 0;
    
    
    // 2. 우선순위 큐에 { 0, start } 넣고 루프 시작
    pq.push({ dist[st], st });
    while(!pq.empty())
    {
        // 가장 dist가 작은 값이 나옴
        auto cur = pq.top();
        pq.pop();
        
        // 그림1. dist의 값과 q에서의 dist가 같은지 검사 -- continue
        if (dist[cur.second] != cur.first) continue;
        
        // q에서 꺼낸 정점과 연결된 모든 정점 검사
        for (auto nxt : adj[cur.second])
        {
            // 그림2. 새로 찾은 경로가 이전 dist보다 작은가? -- continue
            if(dist[nxt.second] <= dist[cur.second] + nxt.first) continue;
            dist[nxt.second] = dist[cur.second] + nxt.first;
            pq.push({ dist[nxt.second], nxt.second });
        }
    }
    
    for (int i = 1; i <= v; i++)
    {
        if(dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    
    return 0;
}