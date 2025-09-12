#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<int> edj[1002];
bool vis[1002];
int n, p; // 컴퓨터의 수, 쌍의 수
void bfs();

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int v, u; // 정점1 - 정점2
	cin >> n;
	cin >> p;
	while (p--)
	{
		cin >> v >> u;
		edj[v].push_back(u);
		edj[u].push_back(v);
	}

	bfs();
	return 0;
}


void bfs()
{
	int count = 0;
	vis[1] = true;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (auto nxt : edj[cur])
		{
			if (vis[nxt]) continue;
			q.push(nxt);
			vis[nxt] = true;
			count++; // 새로운 컴퓨터 방문 - 바이러스 + 1
		}
	}
	cout << count;
}
