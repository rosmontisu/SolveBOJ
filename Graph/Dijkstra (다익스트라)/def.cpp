#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 199991;
vector<pair<int, int>> adj[20002];
int dist[20002];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin >> v >> e;

    int k;
    cin >> k;
    fill(dist, dist + v + 1, INF);
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w, v });
    }
	dist[k] = 0; // dist 초기화 순서 조심하기! (INF로 먼저 초기화 후, 시작점 [k]를 0으로 초기화)
    
    pq.push({ dist[k], k }); // {0, k}

    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();

        if (dist[cur.second] != cur.first) continue;

        for (pair<int, int> nxt : adj[cur.second]) 
        {
            if (dist[nxt.second] <= dist[cur.second] + nxt.first) continue;
                
            dist[nxt.second] = dist[cur.second] + nxt.first;
            pq.push({ dist[nxt.second], nxt.second });
        }
    }




    
    for (int i = 1; i <= v; i++)
    {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }

    return 0;
}