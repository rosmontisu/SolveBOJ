#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int n; cin >> n;
    priority_queue<int> pq; // max heap
    while (n--)
    {
        int a; cin >> a;
        if (a == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else cout << -1 << '\n';
        }
        else
        {
            while (a--)
            {
                int b; cin >> b;
                pq.push(b);
            }
        }
    }
    
    return 0;
}