#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int n, m, k;
int map[1010][1010];
int dist_t[12][1010][1010];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void Bfs()
{
    queue<tuple<int, int, int>> q;
    dist_t[0][1][1] = 1;
    q.push({1, 1, 0});
    while(!q.empty())
    {
        int x, y, wall_count;
        tie(x, y, wall_count) = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int distance = dist_t[wall_count][x][y] + 1;

            if (nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
            if (dist_t[wall_count][nx][ny] > 0) continue;
            if (nx == n && ny == m) 
            {
                dist_t[wall_count][nx][ny] = distance;
                break;
            }
            // 벽이 있다면?
            if (map[nx][ny] && wall_count < k)
            {
                if(dist_t[wall_count+1][nx][ny] > 0) continue; // 벽이 있다면, 해당 차원에서 해당 위치는 어차피 방문이 불가하므로, 상위차원의 방문 여부만 검사하면된다.
                /*
                BFS의 특성상 이미 방문한 곳에 뒤늦게 방문했다는 말은 
                현재 경로가 절대로 더 빠른 경로가 될 수 없다는 말이다.
                */
                                                             
                dist_t[wall_count+1][nx][ny] = distance;// 상위 차원의 거리를 수정해야합니다!!!
                q.push({nx, ny, wall_count + 1});
            }
            // 벽이 없다면?
            if(!map[nx][ny] && dist_t[wall_count][nx][ny] <= 0)
            {
                dist_t[wall_count][nx][ny] = distance;
                q.push({nx, ny, wall_count});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cin >> n >> m >> k;
    const int MAX_NUM = 1004004;
    
    for (int i = 1; i <= n; i++)
    {
        string s; 
        cin >> s;
        for (int j = 0; j < m; j++)
            map[i][j+1] = s[j] - '0';
    }

    Bfs();
    int answer = MAX_NUM;
    for (int i = 0; i <= k; i++) // i < k 가 문제였다
        if(dist_t[i][n][m] > 0)
            answer = min(answer, dist_t[i][n][m]);
    if (answer == MAX_NUM)
        answer = -1;
    cout << answer;
    return 0;
}

/*
맞왜틀??
--> 코드 질문 답장
1. **경계 조건**: 좌표를 확인할 때 1보다 작은지 또는 `n`과 `m` 보다 큰지 비교하는 부분에서 문제가 있을 수 있습니다. 혹시 `nx < 1 || ny < 1 || nx > n || ny > m` 대신 `nx <= 0 || ny <= 0 || nx > n || ny > m`로 해야 할 수도 있어요.

2. **최단거리 갱신**: 특정 위치의 거리 갱신이 올바른지 확인해보세요. 특히 벽을 부수거나 이동할 때 길이가 정확히 갱신되는지요.

3. **초기화 상태**: 배열인 `dist_t`를 초기화하는 부분이 코드에 빠져 있습니다. C++에서는 글로벌 배열이 0으로 초기화되긴 하지만, 명시적으로 초기화해주는 것도 좋은 습관입니다.
   
4. **출력 시 최소 거리**: 최종 `answer` 계산하는 부분에 대한 검토도 필요합니다. 오류가 있다면 최단거리의 값 비교가 올바르게 되었는지 확인해 보세요.

5. **큐 사용법**: 큐의 삽입과 제거 방식에서 실수가 있는지도 체크해보세요. 특히 다중 인덱스에서 값이 제대로 꺼내지고 저장되는지 확인하세요.

전체적인 코드 구조는 괜찮지만, 이러한 부분들을 하나씩 점검해보면 문제 해결에 도움이 될 거예요. 예를 들어, 경계조건을 조금 더 명확하게 체크하는 부분을 추가해볼까요?
*/