#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int p[1005];

int find(int x)
{
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
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
    int n, m;
    cin >> n >> m;
    //  c == 0 이면 불리함

    vector<tuple<int, int, int>> vec;
    for (int i = 0; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vec.push_back({ w, u, v });
    }

    fill(p, p + n + 1, -1);
    sort(vec.begin(), vec.end(), [](auto t1, auto t2) { return get<0>(t1) > get<0>(t2); });
    int cnt = 0;
    for (int i = 0; i <= m; i++)
    {
        int w, u, v;
        tie(w, u, v) = vec[i];
        if (union_(u, v))
            if (w == 0) cnt++;
    }
    int bans = cnt * cnt;

    fill(p, p + n + 1, -1);
    sort(vec.begin(), vec.end(), [](auto t1, auto t2) { return get<0>(t1) < get<0>(t2); });
    cnt = 0;
    for (int i = 0; i <= m; i++)
    {
        int w, u, v;
        tie(w, u, v) = vec[i];
        if (union_(u, v))
            if (w == 0) cnt++;
    }
    int gans = cnt * cnt;

    cout << (bans - gans)* -1;
}