
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int indegree[1001]; // 각 정점의 indegree 저장배열
vector<int> adj[1001]; // my graph
vector<int> result;

int main()
{
    int n, m; // 가수의 수, 입력 줄 수
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int pdCount;
        cin >> pdCount;

        int nodeFirst, nodeSecond;

        // 순서대로 정점이 연결되는 그래프
        // 다음과 같이 간편하게 구현이 가능하다.
        // 첫번째 정점을 입력받아둔다.
        cin >> nodeFirst;
        pdCount--;
        while (pdCount--)
        {
            cin >> nodeSecond;
            adj[nodeFirst].push_back(nodeSecond);
            indegree[nodeSecond]++;
            nodeFirst = nodeSecond; // 다음 연결 그래프를 위해서 시작 정점을 바꿔준다.
        }
    }

    // 위상 정렬 알고리즘
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0) q.push(i);
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        result.push_back(cur);
        for (auto nxt : adj[cur])
        {
            indegree[nxt]--;
            if (indegree[nxt] == 0) q.push(nxt);
        }
    }

    // 위상 정렬이 불가능한지 확인
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] > 0)
        {
            cout << 0;
            return 0;
        }
    }

    // 위상 정렬 그래프 출력
    for (int i = 0; i < n; i++)
        cout << result[i] << '\n';
}
