#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
/*
	회장은 회원들 중에서 점수가 가장 낲은 사람이 됩니다.
	
	출력
	회장의 점수 : 회장 후보의 수	\n
	~회장 후보 오름차순으로 모두 출력~
*/

int n, u, v;
vector<int> adj[52];
int dist[52];

void Bfs(int root)
{
	// bfs 실행시마다 방문 배열을 초기화해야합니다.
	// 이전에는 초기화 전에 vis = true를 해버려서 오류가 발생한겁니다.
	bool vis[52] = { false }; 
	int d[52] = { 0 };

	vis[root] = true;
	int maxDist = 0;

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
	int answer = *min_element(dist + 1, dist + 1 + n); // STL로 최소 거리를 바로 찾을 수 있습니다.
	vector<int> answerMembers;

	for (int i = 1; i <= n; i++)
		if (dist[i] == answer)
			answerMembers.push_back(i);

	// vector.size를 사용하면 더 편하게 크기 출력이 가능합니다.
	cout << answer << ' ' << answerMembers.size() << '\n';
	for (int e : answerMembers)
		cout << e << ' ';
}


int main(void)
{
	cin >> n;
	while (true)
	{
		cin >> u >> v;
		if (u == -1 && v == -1) break;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	// 모든 정점의 dist를 구합니다
	for(int i = 1; i <= n; i++)
		Bfs(i);

	Answer();
	return 0;
}



