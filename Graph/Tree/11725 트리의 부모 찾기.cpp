#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using namespace std;

vector<int> adj[100001];
int p[100001];

void dfs(int cur)
{
	for (int nxt : adj[cur])
	{
		if (p[cur] == nxt) continue; // nxt의 부모가 cur라면 생략
		p[nxt] = cur;
		dfs(nxt);
	}
}

int main(void)
{
	int n; cin >> n;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//cout << "debug 1\n";
	dfs(1);
	for (int i = 2; i <= n; i++)
	{
		cout << p[i] << '\n';
	}
	return 0;
}