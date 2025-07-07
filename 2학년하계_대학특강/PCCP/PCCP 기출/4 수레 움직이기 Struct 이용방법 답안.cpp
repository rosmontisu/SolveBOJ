#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct State {
    int rx, ry;      // 빨강 수레 위치
    int bx, by;      // 파랑 수레 위치
    int turn;        // 현재 턴
    bool rvis[4][4]; // 빨강 수레가 지나간 칸
    bool bvis[4][4]; // 파랑 수레가 지나간 칸
};

int solution(vector<vector<int>> maze) 
{
    int H = maze.size(), W = maze[0].size();
    int rsx, rsy, bsx, bsy, red_tx, red_ty, blue_tx, blue_ty;

    // 시작/도착 위치 찾기
    for (int y = 0; y < H; ++y) 
    {
        for (int x = 0; x < W; ++x) 
        {
            if (maze[y][x] == 1) { rsx = x; rsy = y; }
            if (maze[y][x] == 2) { bsx = x; bsy = y; }
            if (maze[y][x] == 3) { red_tx = x; red_ty = y; }
            if (maze[y][x] == 4) { blue_tx = x; blue_ty = y; }
        }
    }

    queue<State> q;
    State init = {};
    init.rx = rsx; init.ry = rsy;
    init.bx = bsx; init.by = bsy;
    init.turn = 0;
    // 방문 배열 초기화
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            init.rvis[i][j] = init.bvis[i][j] = false;
    init.rvis[rsy][rsx] = true;
    init.bvis[bsy][bsx] = true;

    q.push(init);

    while (!q.empty()) 
    {
        State cur = q.front(); q.pop();

        bool r_arrived = (cur.rx == red_tx && cur.ry == red_ty);
        bool b_arrived = (cur.bx == blue_tx && cur.by == blue_ty);
        if (r_arrived && b_arrived) return cur.turn;

        // 네 방향 조합
        for (int rdir = 0; rdir < 4; ++rdir) 
        {
            for (int bdir = 0; bdir < 4; ++bdir) 
            {
                State nxt = cur;
                nxt.turn = cur.turn + 1;

                // 빨강 이동
                if (!r_arrived) 
                {
                    nxt.ry = cur.ry + dy[rdir];
                    nxt.rx = cur.rx + dx[rdir];
                }
                // 파랑 이동
                if (!b_arrived) 
                {
                    nxt.by = cur.by + dy[bdir];
                    nxt.bx = cur.bx + dx[bdir];
                }
                // 범위 & 벽 체크
                if (nxt.rx < 0 || nxt.rx >= W || nxt.ry < 0 || nxt.ry >= H) continue;
                if (nxt.bx < 0 || nxt.bx >= W || nxt.by < 0 || nxt.by >= H) continue;
                if (maze[nxt.ry][nxt.rx] == 5 || maze[nxt.by][nxt.bx] == 5) continue;

                // 도착 칸에 있으면 고정
                if (r_arrived) { nxt.rx = cur.rx; nxt.ry = cur.ry; }
                if (b_arrived) { nxt.bx = cur.bx; nxt.by = cur.by; }

                // 교차 및 동일 칸 금지
                if (nxt.rx == cur.bx && nxt.ry == cur.by
                    && nxt.bx == cur.rx && nxt.by == cur.ry) continue;
                if (nxt.rx == nxt.bx && nxt.ry == nxt.by) continue;

                // 방문 금지 (각 수레별)
                if (!r_arrived) 
                {
                    if (nxt.rvis[nxt.ry][nxt.rx]) continue;
                    nxt.rvis[nxt.ry][nxt.rx] = true;
                }
                if (!b_arrived) 
                {
                    if (nxt.bvis[nxt.by][nxt.bx]) continue;
                    nxt.bvis[nxt.by][nxt.bx] = true;
                }

                q.push(nxt);
            }
        }
    }

    return 0;
}
