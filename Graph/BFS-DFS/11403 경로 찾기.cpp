#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
입력과 출력 구조가 인접 행렬 형태입니다.
고로, 인접 행렬(2차원 배열)로 풀이합시다
dfs니까 재귀함수로 구현

시작하는 정점을 세로로 잡고, 
dfs로 방문(가능한)하는 모든 정점을 가로축으로 잡으면
추가적인 배열 없이도 깔끔하게 출력이 가능

이때 해당 DFS의 작동 순서를 순서그래프와 인접행렬을 직접 그리고
로직을 따라가보면 좋습니다
*/


int n;
int i, j;


int map[102][102];

int dfs(int depth, int tar)
{
	bool vis[102];
	fill(vis, vis + n, 0);

	stack<int> stk;
	stk.push(depth);

	while (!stk.empty())
	{
		int cur = stk.top();
		stk.pop();

		if (vis[cur]) continue;
		if (cur != depth) vis[cur] = true;	// 같은 depth가 아니면, 방문 true

		// 현재 깊이 순회
		for (int nxt = 0; nxt < n; nxt++)
		{
			if (vis[nxt]) continue;	// 이미 방문했다면 중단
			if (map[cur][nxt] > 0)	// {depth, nxt} 배열에 수가 있는데
			{
				if (nxt == tar) return 1; // 그 수가 찾던 수라면 TRUE
				stk.push(nxt);	// 찾던 숫자가 아니면 더 깊은 곳(다음 숫자)으로 들어갑니다
			}
		}
	}


	return 0;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	

	// 모든 i, j 지점에서 dfs를 돌려서
	// 방문 가능 여부를 출력합니다.
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << dfs(i, j) << ' ';
		cout << '\n';
	}
		
	return 0;
}

