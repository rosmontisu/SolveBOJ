/*
1. Binary를 이용하는 이유? : 모든 숫자는 2의 거듭제곱의 합으로 표현이 가능하기 때문입니다.
2. 2^k 탐색은 왜 안전한가? : 큰 단위부터 확인하는 Greedy접근법이므로(값이 초과되면 사용하지 않음) 안전합니다.
3. DP의 방향? : 모든 노드는 단 1개의 부모만 가집니다. 이 '유일성'때문에 Bottom-Up 방식을 채택합니다.

ㅁ Bottom-Up 계산 과정
parent[k][i] (i의 2^k번째 조상) 테이블을 채우는것이 목표입니다.

1. Base Case
- DFS를 실행하면 모든 노드에 대해 O(N)으로 얻을 수 있습니다.
- parent[0][i] (i의 2^0번째 조상; 즉 i의 부모)

2. 점화식을 이용해 DP테이블 채우기 (k=1, 2, 3...)
 (k=1). parent[1][i] (i의 k^1번째 조상) 2번째 조상
 - i의 2번째 조상 => (i의 부모)의 (부모) = (parent[0][i])의 (부모)
 - parent[1][i] = parent[0][parent[0][i]]

 (k=2). parent[2][i] (i의 k^2번째 조상) 4번째 조상
 - i의 4번째 조상 => (i의 2번째 조상)의 (2번째 조상) = (parent[1][i])의 (2번째 조상)
 - parent[2][i] = parent[1][parent[1][i]]

 (결론)
 parent[k][i] = parent[k-1][parent[k-1][i]]
 - i의 2^k번째 조상 => (i의 2^(k-1)조상)의 (2^(k-1)조상)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 100001;
const int LOG_MAX_N = 17; // N <= 100000 을 기준으로, 2^16 < 100,000 < 2^17. 최대 17번 
vector<int> adj[MAX_N]; // 트리
int parent[LOG_MAX_N][MAX_N]; // parent[k][i] : i의 2^k번째 조상
int depth[MAX_N];


// DFS로 각 노드의 깊이와 직속 부모(Base Case; parent[0][i]) 계산
void dfs(int here, int p, int d)
{
    depth[here] = d;
    parent[0][here] = p;

    for (int there : adj[here])
    {
        // 부모 노드로 돌아가지 않도록 스킾
        if (there == p) continue;
        dfs(there, here, d + 1);
    }
}

// 전체 부모 관계 설정 - 전처리
void set_parent(int n)
{
    // 1. DFS로 depth와 parent[0] 배열 채우기
    dfs(1, 0, 1); // 1번 노드를 루트로

    // 2. parent[k][i]를 DP로 채우기 
    // parent[k][i] = parent[k-1][parent[k-1][i]]
    for (int k = 1; k < LOG_MAX_N; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            // i의 2^(k-1)번째 조상이 존재한다면
            if (parent[k-1][i] != 0)
                parent[k][i] = parent[k-1][parent[k-1][i]];
        }
    }
}

// 두 노드 u,v의 LCA 찾기
int lca(int u, int v)
{
    // 1. u가 더 깊은 노드가 되도록 swap
    if (depth[u] < depth[v]) swap(u, v); 

    // 2. 두 정점의 깊이 맞추기
    for (int k = LOG_MAX_N - 1; k >= 0; k--)
    {
        // u,v의 깊이 차이가 2^k보다 크거나 같다면
        if (depth[u] - depth[v] >= (1 << k))
            u = parent[k][u];
    }

    // 3. 만약 두 노드가 같다면, v가 u의 조상
    if (u == v)
        return u; // (또는 v)

    // 4. 두 정점을 부모 방향으로 동시에 올라가면서 LCA바로 아래까지 탐색
    for (int k = LOG_MAX_N - 1; k >= 0; k--)
    {
        if (parent[k][u] != parent[k][v])
        {
            u = parent[k][u];
            v = parent[k][v];
        }
    }

    return parent[0][u]; // u(또는 v)의 부모가 LCA
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

    // 전처리 O(N log N)
    set_parent(n);

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) 
    {
        int u, v;
        cin >> u >> v;
        // 쿼리당 O(log N)
        cout << lca(u, v) << '\n';
    }

    return 0;
}