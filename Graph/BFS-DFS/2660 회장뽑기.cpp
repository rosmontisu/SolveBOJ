#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
/*
	회장은 회원들 중에서 점수가 가장 낮은 사람이 됩니다.
	
	출력
	회장의 점수 : 회장 후보의 수	\n
	~회장 후보 오름차순으로 모두 출력~
*/
int n;
int u, v;
vector<int> adj[52];
bool vis[52];
int dist[52];

void Bfs(int root)
{
	vis[root] = true;
	int d[52];
	
	int maxDist = 0;

	fill(d, d + 52, 0);
	fill(vis, vis + 52, 0);
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();

		for (auto nxt : adj[cur])
		{
			if (vis[nxt]) continue;
			vis[nxt] = true;
			q.push(nxt);
			d[nxt] = d[cur] + 1;
			if (d[nxt] > maxDist)
				maxDist = d[nxt];
		}
	}
	
	dist[root] = maxDist;
}

void Answer()
{
	int answer = 53;
	int answerCount = 0;
	vector<int> answerMembers;

	for (int i = 1; i <= n; i++)
		if (dist[i] < answer && dist[i] > 0)
			answer = dist[i];

	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == answer)
		{
			answerCount++;
			answerMembers.push_back(i);
		}
	}

	cout << answer << ' ' << answerCount << '\n';
	for (int e : answerMembers)
		cout << e << ' ';
}

int main(void)
{
	cin >> n;
	while (true)
	{
		cin >> u >> v;
		if (u + v < 0) break;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// 모든 정점의 dist를 구합니다
	for(int i = 1; i <= n; i++)
		Bfs(i);

	Answer();
	return 0;
}