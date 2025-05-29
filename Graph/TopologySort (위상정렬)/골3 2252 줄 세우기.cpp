#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int degree[100001]; // 각 정점의 indegree 수를 저장
vector<int> adj[100001]; // my graph
queue<int> q; // indegree == 0 저장용 큐

vector<int> result; // 정답 출력용

int main()
{
    int n, m; // 학생수, 비교수
    cin >> n >> m;

    // m회 비교
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        degree[b]++; // b는 indegree증가
    }

    for (int i = 1; i <= n; i++)
        if (degree[i] == 0) q.push(i);

    // 위상 정렬 알고리즘 시작
    // BFS를 기반으로 작동한다는걸 볼 수 있다.
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        result.push_back(cur); // 위상 정렬
        for (int nxt : adj[cur])
        {
            degree[nxt]--;
            if (degree[nxt] == 0) q.push(nxt);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i] << ' ';
    }

    return 0;
}