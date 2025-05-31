// https://yuminlee2.medium.com/union-find-algorithm-ffa9cd7d2dba
// 최적화 시각화 자료

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> p(1000002, -1);

int find(int x)
{
    if (p[x] < 0) return x;
    return p[x] = find(p[x]); // path compression
}

bool union_(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return false;

    // union by rank
    if (p[v] < p[u]) // v의 rank가 더 높으면, swap해서 큰 트리에 작은 트리가 먹히도록 유도 -> rank가 증가하지 않는다!
        swap(u, v);
    if (p[u] == p[v])
        p[u]--;

    p[v] = u; // root u - v

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    if (n == 1) 
    {
        cout << 0; // 정점이 1개면 이미 모두 연결댐
        return 0;
    }

    int cnt = n;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if(union_(u, v)) cnt--; // 새 정점이 연결되면 cnt - 1
        if (cnt == 1)
        {
            cout << i + 1; // 모두 연결되었으면, 중단하고 몇번째인지 출력
            return 0;
        }
    }
    
    cout << -1; // 연결 실패
}