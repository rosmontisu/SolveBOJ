#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool visit[10][10][10][10];

int solution(vector<vector<int>> maze) 
{
    // 파랑/빨강 수레를 동시에 delta 조정하면서 bfs돌리면 될듯
    // 수레 위치, 도착지 위치 초기화
    int rx, ry, bx, by, turn = 0;
    int end_rx, end_ry, end_bx, end_by;
    for (int y = 0; y < maze.size(); y++)
    {
        for (int x = 0; x < maze[0].size(); x++)
        {
            if (maze[y][x] == 1)
            {
                rx = x;
                ry = y;
            }
            if (maze[y][x] == 2)
            {
                bx = x;
                by = y;
            }
            if (maze[y][x] == 3)
            {
                end_rx = x;
                end_ry = y;
            }
            if (maze[y][x] == 4)
            {
                end_bx = x;
                end_by = y;
            }
        }
    }
    
    // 빨강 x y 파랑 x y 턴 0
    queue<tuple<int, int, int, int, int>> q;
    q.push({ ry, rx, by, bx, 0 });
    visit[ry][rx][by][bx] = true;
    
    // BFS 시작
    while (!q.empty())
    {
        int crx, cry, cbx, cby, cturn = 0;
        tie(cry, crx, cby, cbx, cturn) = q.front();
        q.pop();
        
        bool r_arrived = (end_rx == crx && end_ry == cry);
        bool b_arrived = (end_bx == cbx && end_by == cby);
        if (r_arrived && b_arrived) return cturn; // 수레가 모두 목적지에 도착!
        
        int rdir_max = 4; int bdir_max = 4;
            
        for (int rdir = 0; rdir < rdir_max; rdir++)
        {
        for (int bdir = 0; bdir < bdir_max; bdir++)
        {
            int nry = cry, nrx = crx, nby = cby, nbx = cbx;
            
            if (!r_arrived)
            {
                nry = cry + dy[rdir];
                nrx = crx + dx[rdir];
            }
            if (!b_arrived)
            {
                nby = cby + dy[bdir];
                nbx = cbx + dx[bdir];
            }
            
            // 예외처리 목록
            // 수레 교차 금지
            if (nrx == cbx && nry == cby && nbx == crx && nby == cry) continue; 
            // 동일 위치 금지
            if (nrx == nbx && nry == nby) continue; 
            // 맵 초과
            if (nrx < 0 || nry < 0 || nbx < 0 || nby < 0 || 
                nrx >= maze[0].size() || nry >= maze.size() || 
                nbx >= maze[0].size() || nby >= maze.size()) continue;    
            // 벽
            if (maze[nry][nrx] == 5 || maze[nby][nbx] == 5) continue;
            // 방문 
            if (visit[nry][nrx][nby][nbx]) continue;
            
            visit[nry][nrx][nby][nbx] = true;
            q.push({ nry, nrx, nby, nbx, cturn + 1 });
        }
        }
        
    }
    return 0;
}