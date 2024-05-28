#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// S를 시작점으로 모든 경우의 수를 dist==7까지 BFS()를 돌리낟.
// 이때, BFS의 결과값으로 S>=4 충족하면 정답 count + 1;

char map[5][5];
int dist[5][5];
int count = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int Bfs()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty())
    {
        
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; i ++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++)
            map[i][j] = s[j];
    }
}