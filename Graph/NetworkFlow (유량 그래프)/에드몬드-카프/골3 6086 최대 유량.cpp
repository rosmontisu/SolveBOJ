#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int c[150][150]; // capacity
int f[150][150]; // flow 0
vector<int> adj[150]; // 파이프 연결 list

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        char u, v;
        int w;
        cin >> u >> v >> w;

        // ('A'<=u && u<='Z' ? u-='A' : u-='a');
        // ('A'<=v && v<='Z' ? v-='A' : v-='a');
        
        c[u][v] += w;
        c[v][u] += w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    while (true)
    {
        // S(source) -> T(target; sink)
        int s = 'A';
        int t = 'Z';

        vector<int> p(150, -1); // BFS 기록용
        queue<int> q;
        q.push(s);
        p[s] = s; // 시작점 부모

        // BFS로 가능한 파이프 경로 찾기
        while (!q.empty())
        {
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur])
            {
                if (p[nxt] != -1) continue; // 이미 방문
                if (c[cur][nxt] - f[cur][nxt] <= 0) continue; // 이미 다씀

                q.push(nxt);
                p[nxt] = cur; 
                if (nxt == t) break; // sink 도착
            }
        }

        // BFS로 sink에 도달 못함. (최대 유량임)
        if (p[t] == -1) break;

        // 거슬러 올라가면서 최소 찾기
        int amount = INF;
        for (int cur = t; cur != p[s]; cur = p[cur])
            amount = min(amount, (c[p[cur]][cur] - f[p[cur]][cur]));
        for (int cur = t; cur != p[s]; cur = p[cur])
        {
            f[p[cur]][cur] += amount; // 정방향 : 유량 늘림
            f[cur][p[cur]] -= amount; // 역방향 : 유량 줄임 (다시 빼는경우)
        }
        ans += amount;
    }

    cout << ans;
    return 0;
}
