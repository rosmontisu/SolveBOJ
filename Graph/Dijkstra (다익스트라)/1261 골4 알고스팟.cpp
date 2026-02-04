#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dist[125][125];
int map[125][125];

int main()
{
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dist[i][j] = 0x3f3f3f3f; // 초기화
            cin >> map[i][j]; // 0, 1 입력
        }
    }

    // 0,0 -> n-1,m-1

    
}
