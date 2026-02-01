#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

char map[55][55];
bool visit[55][55];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
    int r, c;
    cin >> r >> c;

    pair<int, int> st, ed;
    queue<pair<int, int>> water;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'S')
            {
                st.first = i;
                st.second = j;
            }
            if (map[i][j] == 'D')
            {
                ed.first = i;
                ed.second = j;
            }
            if (map[i][j] == '*')
            {
                water.push({ i, j });
            }
        }
    }

    int ans = 0;
    queue<pair<int, int>> q;
    q.push(st);
    visit[st.first][st.second] = true;
    while(!q.empty())
    {
        int wsize = water.size(); // push에 변함. 미리 빼놔야함
        for (int i = 0; i < wsize; i++)
        {
            auto cur = water.front(); water.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                if (map[nx][ny] == 'X' || map[nx][ny] == 'D' || map[nx][ny] == '*') continue;
                map[nx][ny] = '*';
                water.push({ nx, ny });
            }
        }

        int qsize = q.size(); // push에 변함. 미리 빼놔야함
        for (int i = 0; i < qsize; i++)
        {
            auto cur = q.front(); q.pop();
            if (cur == ed)
            {
                cout << ans;
                return 0;
            }

            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                if (visit[nx][ny]) continue;
                if (map[nx][ny] == 'X' || map[nx][ny] == '*') continue; // 벽, 물

                visit[nx][ny] = true;
                q.push({ nx, ny });
            }
        }

        ans += 1;
    }

    cout << "KAKTUS";
}