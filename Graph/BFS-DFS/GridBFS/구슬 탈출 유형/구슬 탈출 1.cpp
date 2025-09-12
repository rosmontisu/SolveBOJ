#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char map[15][15];
bool visit[15][15][15][15]; // ry rx by bx

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

// struct로 푸는거 연습
struct State {
    int ry, rx;
    int by, bx;
    int moves; // 이동 횟수
};

// 구슬 하나를 굴릴때, 최종위치 및 구멍에 빠지는가?
tuple<int, int, bool> roll(int y, int x, int dir)
{
    bool inHole = false;
    while (true)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if (map[ny][nx] == '#') break; // 벽
        
        // 구멍
        if (map[ny][nx] == 'O')
        {
            inHole = true;
            x = nx; y = ny;
            break;
        }
        
        // 빈 공간, 이동
        x = nx; y = ny;
    }
    
    return { y, x, inHole };
}

int bfs(int n, int m, State start)
{
    queue<State> q;
    q.push(start);
    visit[start.ry][start.rx][start.by][start.bx] = true;
    while (!q.empty())
    {
        State cur = q.front(); q.pop();
        if (cur.moves >= 10) continue; // 상한 초과
        
        for (int dir = 0; dir < 4; dir++)
        {
            auto [nry, nrx, rHole] = roll(cur.ry, cur.rx, dir);
            auto [nby, nbx, bHole] = roll(cur.by, cur.bx, dir);
            
            if (bHole) continue; // 실패 
            if (rHole) return cur.moves + 1; // 성공, 횟수 반환
            
            // 두 구슬이 겹치면, 뒤에 오는 구슬이 1칸 위로
            if (nry == nby && nrx == nbx)
            {
                // 많이 이동 -> 전 후 거리비교 하면댐
                int rDist = abs(nry - cur.ry) + abs(nrx - cur.rx);
                int bDist = abs(nby - cur.by) + abs(nbx - cur.bx);
                if (rDist > bDist)
                {
                    nry -= dy[dir];
                    nrx -= dx[dir];
                }
                else
                {
                    nby -= dy[dir];
                    nbx -= dx[dir];
                }
            }
            
            if (!visit[nry][nrx][nby][nbx])
            {
                visit[nry][nrx][nby][nbx] = true;
                q.push({ nry, nrx, nby, nbx, cur.moves + 1 });
            }
        }
    }
    
    return -1; // 실패
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    
    // 맵 초기화
    State start;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> map[y][x];
            if (map[y][x] == 'B') { start.bx = x; start.by = y; };
            if (map[y][x] == 'R') { start.rx = x; start.ry = y; };
        }
    }
    
    start.moves = 0;
    
    if (bfs(n, m, start) > 0)
        cout << 1;
    else
        cout << 0;
    
    return 0;
}