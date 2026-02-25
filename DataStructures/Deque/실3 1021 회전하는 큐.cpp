#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    int n, m; 
    cin >> n >> m; // 크기, 뽑을 수
    deque<int> dq;
    for (int i = 1; i <= n; i++)
        dq.push_back(i);

    // 1. front_pop
    // 2. <<-
    // 3. ->>

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int x; cin >> x;
        auto it = find(dq.begin(), dq.end(), x);
        int idx = it - dq.begin();
        if (idx == 0) dq.pop_front();
        else if (idx <= dq.size() - idx) // 앞
        {
            while(idx--)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
            dq.pop_front();
        }
        else // 뒤
        {
            idx = dq.size() - idx;
            while (idx--)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
            dq.pop_front();
        }
    }

    cout << cnt;
}