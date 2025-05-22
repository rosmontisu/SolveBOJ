#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n; // 도시 수
    cin >> m; // 버스 수

    const int INF = 0x3f3f3f3f; // 최대 거리
    vector<vector<pair<int, int>>> adj(n + 1); // 인접 리스트

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w; // u -(w)-> v

        adj[u].push_back({ v, w });
    }

    int st, ed;
    cin >> st >> ed; // 시작점, 도착점

    vector<int> dist(n + 1, INF); // 거리 배열
    vector<int> pre(n + 1, 0); // 경로 기록 배열
    dist[st] = 0; // 시작점 거리 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // deque가 아닌 vector 사용 명시, min heap

    pq.push({ dist[st], st }); // 최단거리 넣어주고 시작

    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();

        int now_dist = cur.first;
        int now_vertex = cur.second;

        if (dist[now_vertex] < now_dist) continue; // 현재 경로는 최단 경로가 아님 (더 나은 경로가 이미 dist에 존재)

        for (auto nxt : adj[now_vertex])
        {
            int nxt_vertex = nxt.first;
            int dist_nxt = nxt.second;

            int dist_sum = dist[now_vertex] + dist_nxt;

            if (dist[nxt_vertex] > dist_sum)
            {
                dist[nxt_vertex] = dist_sum;
                pq.push({ dist[nxt_vertex], nxt_vertex }); // 새로운 최단 경로를 찾았으므로 push
                pre[nxt_vertex] = now_vertex; // nxt는 now를 거쳐 왔다는걸 기록
            }
        }
    }

    // 1. st에서 ed까지의 비용
    cout << dist[ed] << '\n';

    // 2. st에서 ed까지 도시 수 (st, ed 포함)
    vector<int> path;
    int cur = ed;
    int cnt = 1;
    
    while (cur != st)
    {
        path.push_back(cur);
        cur = pre[cur];
        cnt++;
    }
    path.push_back(cur);
    cout << cnt << '\n';

    // 3. st에서 ed까지 도시 방문 순서
    reverse(path.begin(), path.end());
    for (auto p : path) cout << p << ' ';
}