// M개의 쿼리가 주어질때 총 시간복잡도는 O(N + M*N)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1000002;

vector<int> adj[MAX_N]; // 트리
int parent[MAX_N];      // 각 노드의 부모 노드
int depth[MAX_N];       // 각 노드의 깊이 (루트 1)

// DFS로 각 노드의 깊이와 부모를 계산
void dfs(int here, int p, int d) // 기준노드, 깊이, 부모
{
    depth[here] = d;
    parent[here] = p;

    for (int there : adj[here])
    {
        // 부모 노드로 돌아가지 않도록 스킾
        if (there == p) continue;
        dfs(there, here, d + 1);
    }
}

// 두 노드 u,v의 LCA 찾기
int lca(int u, int v)
{
    
    // 1. u가 더 깊은 노드가 되도록 swap
    if (depth[u] < depth[v]) swap(u, v); 

    // 2. 두 정점의 깊이 맞추기
    while (depth[u] != depth[v])
        u = parent[u];

    // 3. 만약 두 노드가 같다면, v가 u의 조상이지만, 위에서 swap하였으므로 상관 X

    // 4. 두 정점을 부모 방향으로 동시에 올라가면서 서로 만날때까지 탐색
    while (u != v)
    {
        u = parent[u];
        v = parent[v];
    }

    return u;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    // 트리 생성
    for (int i = 0; i < n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 1); // parent[1] = 0, depth[1] = 1 

    int m; // LCA 서치 쿼리 수 
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }

    return 0;
}