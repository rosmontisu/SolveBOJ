#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<int> vec(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> vec[i];

        int cnt = 0;
        vector<bool> vis(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            // 사이클 찾았음
            if (vis[i] == false)
            {
                cnt += 1; 
                int cur = i;

                // DFS
                while (vis[cur] == false)
                {

                    vis[cur] = true;
                    cur = vec[cur];
                }
            }
        }

        cout << cnt << '\n';
    }
}