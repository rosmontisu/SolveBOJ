#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> vec(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> vec[i];
    
    // 웅나 수 = n탐색 돌리기 
    // 웅나 시간 = n - 사이클의 수

    int cnt1 = 0;
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            int cur = i;
            cnt1 += 1; // 사이클 시작점 발 견
            while (vis[cur] == false)
            {
                vis[cur] = true;
                cur = vec[cur];
            }
        }
    }

    // 내림차순 검사 { 4 3 2 1 } 케이스
    int cnt2 = 0;
    vis.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            int cur = i;
            cnt2 += 1; // 사이클 시작점 발 견
            while (vis[cur] == false)
            {
                vis[cur] = true;
                cur = vec[n - cur + 1];
            }
        }
    }
        
    cout << n - 2 << ' ' << n - max(cnt1, cnt2);
}