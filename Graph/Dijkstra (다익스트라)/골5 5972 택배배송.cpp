/*
6 8
4 5 3
2 4 0
4 1 4
2 1 1
5 6 1
3 6 2
3 2 6
3 4 4
*/
    
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dist[50005];
const int INF = 0x3f3f3f3f;
vector<pair<int, int>> vec[50005]; // u -> (w) -> v
 
int main()
{
    int n, m;
    cin >> n >> m;
    fill(dist, dist + n + 1, INF);
    
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back({ w, v });
        vec[v].push_back({ w, u });
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[n] = 0;
    pq.push({ dist[n], n });
    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if (cur.first != dist[cur.second]) continue;
        for (auto nxt : vec[cur.second])
        {
            if (dist[nxt.second] <= nxt.first + dist[cur.second]) continue;
            dist[nxt.second] = nxt.first + dist[cur.second];
            pq.push({ dist[nxt.second], nxt.second });
        }
    }
    
    cout << dist[1];
}