#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

vector<int> map[105];
bool visited[105];

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }
    
    int answer = 0;
    queue<int> q;

    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        auto cur = q.front(); q.pop();

        for (int nxt : map[cur])
        {
            if (!visited[nxt])
            {
                visited[nxt] = true;
                answer++;
                q.push(nxt);
            }
        }
    }
    
    cout << answer;
}