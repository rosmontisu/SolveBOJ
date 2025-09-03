#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

vector<int> p(5005, -1);

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

double weight(double x1, double y1, double x2, double y2)
{
    return sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
}

vector<tuple<double, int, int>> edges;
int main()
{
    int n; cin >> n;
    if (n == 1) cout << 0;

    vector<pair<double, double>> pos(n);
    for (int i = 0; i < n; i++)
        cin >> pos[i].first >> pos[i].second;
    
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double w = weight(pos[i].first, pos[i].second, pos[j].first, pos[j].second);
            edges.push_back({ w, i, j });
        }
    }

    sort(edges.begin(), edges.end());

    int cnt = 0;
    double ans = 0;

    for (int i = 0; i < edges.size(); i++)
    {
        double w;
        int u, v;
        tie(w, u, v) = edges[i];
        if (union_(u, v))
        {
            cnt++;
            ans += w;
        }
        if (cnt == n - 1) break;
    }

    printf("%.2f", ans);

    return 0;
}