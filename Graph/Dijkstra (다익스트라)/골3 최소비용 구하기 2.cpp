#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int main()
{
    int n, m;
    cin >> n; // 도시 수
    cin >> m; // 버스 수

    const int INF = (n-1) * (1000000-1) + 1; // 최대 거리
    vector<vector<pair<int, int>>> adj(n + 1); // 인접 리스트

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w; // u -(w)-> v

        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w }); // 양방향
    }

    int st, ed;
    cin >> st >> ed; // 시작점, 도착점

    vector<int> dist(n + 1, INF); // 거리 배열
    dist[st] = 0; // 시작점 거리 0
}