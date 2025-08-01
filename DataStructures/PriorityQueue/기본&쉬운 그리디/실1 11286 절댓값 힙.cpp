#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int n; cin >> n;
    while(n--)
    {
        int x; cin >> x;
        
        if (x == 0)
        {
            if (pq.empty()) cout << 0 << '\n';
            else
            {
                cout << pq.top().second << '\n'; 
                pq.pop();
            }
        }
        else pq.push({abs(x), x});
    }
} 
