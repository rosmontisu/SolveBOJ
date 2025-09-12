#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

queue<pair<int, int>> Q;
bool vis[502][502];
int map[502][502];

int n, m;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			cin >> map[i][j];

	int maxArea = 0;
	int num = 0;

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (map[i][j] == 0 || vis[i][j]) continue;

			// 새로운 그림의 시작점을 찾음
			num++; 
			vis[i][j] = true;
			Q.push({ i, j });
			int area = 0;
			while (!Q.empty()) 
			{
				area++;
				pair<int, int> cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) 
				{
					int nowX = cur.first + dx[dir];
					int nowY = cur.second + dy[dir];
					if (nowX < 0 || nowY < 0 || nowX >= n || nowY >= m)
						continue;
					if (vis[nowX][nowY] || map[nowX][nowY] != 1)
						continue;
					Q.push({ nowX,nowY });
					vis[nowX][nowY] = true;
				}
			}
			if (area > maxArea)
				maxArea = area;
		}
	}

	cout << num << "\n";
	cout << maxArea;
}
