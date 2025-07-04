#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<int> adj[105];
bool visit[105];

int solution(int n, vector<vector<int>> wires) 
{
    int answer = n+1;
    // n <= 100 
    // 브루트포스하게 풀어도 상관없을듯?
    
    // 인접리스트로 트리 생성
    for (auto cur : wires)
    {
        adj[cur[0]].push_back(cur[1]);
        adj[cur[1]].push_back(cur[0]);
    }
     
    // 0번 간선부터 전부 1번씩 잘라서 새 트리를 만들기
    for (int i = 0; i < wires.size(); i++)
    {
        int cut_u = wires[i][0];
        int cut_v = wires[i][1];
        for (int j = 0; j < 105; j++)
            visit[j] = false;
        
        int count = 1;
        queue<int> q;
        q.push(1); // 1번 정점부터 탐색
        visit[1] = true;
        
        while (!q.empty())
        {
            int cur = q.front(); q.pop();

            for (int nxt : adj[cur])
            {
                if (visit[nxt]) continue;
                if (cur == cut_u && nxt == cut_v || cur == cut_v && nxt == cut_u) continue; // 잘린거면 생략
                
                visit[nxt] = true;
                count++;
                q.push(nxt);
            }
        }
        
        // 전체 정점의 수 - 새로 구한 정점의 수 = 반대편 정점수
        answer = min (answer, ((n - count) - count) > 0 ? ((n - count) - count) : ((n - count) - count) * -1);
    }
    
    return answer;
}