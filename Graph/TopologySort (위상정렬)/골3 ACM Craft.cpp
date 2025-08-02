#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);    // u -> v
        indegree[v]++;          // v 진입차수++
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0) 
            pq.push(i); 
    }
        
    vector<int> ans;
    while (!pq.empty())
    {
        int cur = pq.top(); pq.pop();
        //cout << cur << ' ';
        ans.push_back(cur);
        
        // 차수 줄이고, 0되면 또 넣고
        for (int nxt : adj[cur]) 
        {
            indegree[nxt]--; 
            if (indegree[nxt] == 0) 
                pq.push(nxt);
        }
    }

    for (int a : ans)
        cout << a << ' ';
    return 0;
}