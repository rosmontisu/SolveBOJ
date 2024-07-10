#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

// map은 NxN 크기
int n, m;
int input;

int total = 0;

int map[52][52];
int dist[52][52];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

queue<pair<int, int>> home;
queue<pair<int, int>> chicken;

int answer(int depth)
{
    // base condition
    if (depth == m)
    {
        return total;
    }
}

void initDist()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = 0;
}

int bfs(pair<int, int> p)
{
    //int result = 0;
    queue<pair<int, int>> q;
    q.push(p);

    initDist();

    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dx[i];

            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if (dist[nx][ny] > 0) continue;

            q.push({ nx, ny });
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            //cout << "1\n";

            if (map[nx][ny] == 2)
            {
                //cout << "2\n";
                return dist[nx][ny];
            }
        }
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
                home.push({ i, j });
            else if (map[i][j] == 2)
                chicken.push({ i, j });
        }
    }


    // 현재 경우의 모든 집의 거리의 최소값을 더합니다.
    int distSum = 0;
    while (!home.empty())
    {
        distSum += bfs(home.front()); home.pop();
    }

    cout << distSum <<'\n';




    return 0;
}