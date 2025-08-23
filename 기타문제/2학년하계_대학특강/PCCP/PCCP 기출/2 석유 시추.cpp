#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool visit[505][505];
int answer[505]; // 열단위로 데이터 압축 - x좌표 기준

int solution(vector<vector<int>> land) 
{
    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land[0].size(); j++)
        {
            // 석유있고, 검사 안했음 -> BFS 시작
            if (!visit[i][j] && land[i][j] > 0)
            {
                queue<pair<int, int>> q;
                q.push({ j, i }); // x, y
                visit[i][j] = true;
                
                int sum_oil = 0;
                set<int> set_oil; // 중복 x, 열기록
                
                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();
                    
                    sum_oil++;
                    set_oil.insert(cur.first); // 오일이 있는 x좌표 기록
                    
                    // 석유가 있는곳만 q에 넣기
                    for (int i = 0; i < 4; i++)
                    {
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];
                        
                        if (nx < 0 || ny < 0 || nx >= land[0].size() || ny >= land.size()) continue; // 맵
                        if (visit[ny][nx]) continue; // 이미 방문
                        if (land[ny][nx] == 0) continue; // 석유 x
                        
                        visit[ny][nx] = true;
                        q.push({ nx, ny });
                    }
                }
                
                // 현재 bfs로 찾은 오일덩어리가 겹친 x좌표에 모두 기록
                for (int oil_idx : set_oil)
                    answer[oil_idx] += sum_oil;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < land[0].size(); i++)
        ans = max(ans, answer[i]);
    
    return ans;
}