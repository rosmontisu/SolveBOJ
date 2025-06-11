// https://yuminlee2.medium.com/union-find-algorithm-ffa9cd7d2dba
// 최적화 시각화 자료

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> p(100002, -1);

int find(int x)
{
    if (p[x] < 0)
        return x;
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
    int t;
    cin >> t; // 전체 테케

    for (int j = 1; j <= t; j++)
    {
        fill(p.begin(), p.end(), -1); // - 벡터의 위치와 초기화 조심하자
        int n, k, a, b, m, u, v;
        cin >> n; // 유저 수
        cin >> k; // 친구 관계 수
        
        for (int i = 0; i < k; i++)
        {
            cin >> a >> b; // a b 친구
            union_(a, b);
        }
        cin >> m; // 미리 구할 쌍의 수
        cout << "Scenario " << j << ":\n";
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v; // 구해야 하는 쌍
            if (find(u) == find(v))
                cout << "1\n";
            else
                cout << "0\n";
        }
        cout << '\n';
    }
}