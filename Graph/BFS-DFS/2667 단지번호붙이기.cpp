#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

char map[26][26];
bool visit[26][26];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n;
int BFS(int i, int j);

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			visit[i][j] = false;
		}
	}

	int count = 0;
	int area;
	vector<int> answer;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] == false && map[i][j] == '1') {
				area = BFS(i, j);
				answer.push_back(area);
				count++;
				//cout << count;
			}
		}
	}

	sort(answer.begin(), answer.end());
	cout << count << '\n';
	for (int i = 0; i < count; i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}

int BFS(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i, j });
	
	int area = 1;
	visit[i][j] = true;
	/*
	초기 위치는 무조건 area이므로 1로 초기화 한 후 방문값을 true로 바꿔준다.
	관련 반례

	5
	00000
	00000
	00100
	00000
	00000
	*/

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = dx[dir] + cur.first;
			int ny = dy[dir] + cur.second;

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (map[nx][ny] == '0' || visit[nx][ny] == true) continue;
			
			area++;
			visit[nx][ny] = true;
			q.push({ nx, ny });
		}
	}

	return area;
}
