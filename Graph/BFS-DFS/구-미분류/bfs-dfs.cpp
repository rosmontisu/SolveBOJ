#include <iostream>
#include <vector>
#include <memory.h> // memset() 쓰기 위해서
#include <algorithm>
#include <queue>
using namespace std;

vector<int> vec[10002];     // 그래프 그리는 용

vector<int> result_bfs;     // bfs 정답(출력) 기록
vector<int> result_dfs;     // dfs 정답(출력) 기록
bool visit[10002];          // node 방문 체크


// queue로 bfs 구현
void bfs(int temp)
{
    queue<int> q;
    q.push(temp);
    visit[temp] = true; // 해당 번호 탐색 기록

    // queue가 빌때까지 반복한다.
    // 
    while (!q.empty())
    {
        int x = q.front(); q.pop();
        result_bfs.push_back(x);

        for (int i = 0; i < vec[x].size(); i++)
        {
            if (!visit[vec[x][i]]) // 해당 노드부터 bfs 시작
            {
                q.push(vec[x][i]);
                visit[vec[x][i]] = true;
            }
        }
    }
}

void dfs(int x)
{
    visit[x] = true;    // 시작 node 방문 true
    result_dfs.push_back(x);    // 시작 node가 어차피 1번이다

    for (int i = 0; i < vec[x].size(); i++)
    {
        // 아래 구조는 직접 그래프를 그려보면
        // 직관적으로 쉽게 이해가 가능함
        if (!visit[vec[x][i]]) // 해당 벡터의 숫자에 방문한 적이 있는가?
        {
            // 재귀구조
            // 방문한 적이 없다면 해당 숫자에서 더 깊게 탐색 시작(dfs)
            dfs(vec[x][i]); 
        }
    }
}

int main(void)
{
    // 정점, 간선, 시작번호
    int vertex, edge, startNumber;
    cin >> vertex >> edge >> startNumber;

    // 정점1 - 정점2
    int a, b;
    for (int i = 1; i <= edge; i++)
    {
        cin >> a >> b;
        // a번 vector 뒤에 b 연결
        // b번 vector 뒤에 a 연결
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for (int i = 1; i <= vertex; i++)
    {
        // vec.begin(), vec.end()
        // 벡터의 첫숫자, 마지막 숫자

        sort(vec[i].begin(), vec[i].end()); 
        // 낮은 숫자부터 탐색하기 위해
        // 오름차순으로 sort 해준다
        // 직접 그려보면 알겠지만 vecttor를 정렬한다고
        // 그래프가 변하지는 않는다.
    }

    

    // void* memset(void* ptr, int value, size_t num);
    // value는 내부에서 unsigned char로 변환된다.
    // 즉 문자를 넣어도 무방하다
    // return -> ptr / (실패시)NULL
    bfs(startNumber);
    memset(visit, false, sizeof(visit));
    dfs(startNumber);

}
