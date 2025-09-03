#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
using namespace std;

tuple<int, int, int> edge[100005];

vector<int> p(100005, -1);
int find(int x)
{
    if (p[x] < 0) return x;
    int root = find(p[x]);
    p[x] = root;
    return root;
}

bool union_(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return false;

    if (p[u] > p[v]) swap(u, v);
    if (p[u] == p[v]) p[u]--;
    p[v] = u;
    return true;
}


int main()
{
    int n; cin >> n;
    int m; cin >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = { w, u, v };
    }

    sort (edge + 1, edge + 1 + m);

    int cnt = 0;
    int ans = 0;

    for (int i = 1; i <= m; i++)
    {
        int w, u, v;
        tie(w, u, v) = edge[i];
        if (union_(u, v))
        {
            cnt++;
            ans += w;
        }

        if (cnt == n - 1) break;
    }

    cout << ans;
}