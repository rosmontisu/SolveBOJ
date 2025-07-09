// O(V+E)
// Bipartite graph - BFS

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int> adj[20001]; // 당분간 인접리스트 방식 연습
int colors[20001]; // 0 미방문, 1~2 방문 그룹

// BFS 풀이 - is bipartite graph?
bool isBipartite(int st)
{
    queue<int> q;
    q.push(st);
    colors[st] = 1; // 시작 노드를 1번 그룹에 추가
    
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u])
        {
            if (colors[v] == 0) // 아직 미방문 노드라면
            {
                colors[v] = (3 - colors[u]); // 현재 노드와 다른 그룹으로 저장 (3-1=2, 3-2=1)
                q.push(v); // 다음 탐색에 추가
            }
            else if (colors[v] == colors[u]) return false; // 인접 노드가 같은 그룹 (bipartite graph x)
        }
    }
    
    return true;
}

int main()
{
    int k; cin >> k;
    while (k--)
    {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        
        int v, e; cin >> v >> e;
        
        // 루프마다 초기화
        for (int i = 1; i <= v; i++) adj[i].clear();
        memset(colors, 0, sizeof(colors));
        
        for (int i = 0; i < e; i++)
        {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        bool answer = true;
        for (int i = 1; i <= v; i++)
        {
            if (colors[i] == 0)
            {
                if (!isBipartite(i))
                {
                    answer = false;
                    break;
                }
            }
        }
        
        if (answer) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
