#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
bfs로 거리를 측정
거리가 1or2인 친구들의 수를 카운트 -> 출력
*/

int n, m; // 동기의 수, 리스트의 길이
vector<int> edj[10002];
bool vis[10002];
int dist[10002];
void bfs();
int main(void)
{
	cin >> n;
	cin >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		//방향성이 없는 그래프이므로 양쪽을 모두 이어줍니다
		edj[b].push_back(a);
		edj[a].push_back(b);
	}

	bfs();
	return 0;
}

void bfs()
{
	int count = 0;
	int prv_dist = 0;

	dist[1] = 0; // 시작점
	
	queue<int> q;
	vis[1] = true;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto nxt : edj[cur])
		{
			if (vis[nxt]) continue;
			vis[nxt] = true;
			q.push(nxt);
			dist[nxt] = dist[cur] + 1;


			if (dist[nxt] <= 2)
				count++;
		}
	}

	cout << count;
}
