#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 연결 요소의 개수를 출력합시다
/*
그래프를 구현 후, 
미방문한 v에서 bfs를 돌린다.	-> visit[v] = true
bfs가 끝날때마다 1씩 카운트를 증가시킨다. 
다시 미방문한 v에서 bfs를 돌리고, 모든 정점을 방문하면 중단. 
카운트된 횟수를 출력한다.

// queue로 푸쉬/visit = true
// queue에서 pop/visit 검사 

-> dfs/recursion dfs 모두 가능
*/

bool vis[1002];
vector<int> adj[1002];
int n, m;


void bfs()
{
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue; // 방문시? skip
		answer++; // 새로운 시작 정점을 찾음
		queue<int> q;
		q.push(i);
		vis[i] = true; // 방문 완료
		while (!q.empty()) 
		{
			int cur = q.front();
			q.pop();

			// adj[i]로 해서 오류가..
			for (auto nxt : adj[cur]) // queue에서 꺼낸 cur정점에 연결된 모든 정점 검색 시작
			{
				if (vis[nxt]) continue;
				q.push(nxt);
				vis[nxt] = true;
			}
		}
	}

	cout << answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;

	while (m--)
	{
		int u, v;

		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	bfs();

	return 0;
}
