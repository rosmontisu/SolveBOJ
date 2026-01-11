#include <iostream>
#include <vector>
using namespace std;
struct Point
{
    long long x, y;
};
int main()
{
    int n, m; cin >> n >> m;
    vector<Point> v1(n);
    vector<Point> v2(m);
    for (int i = 0; i < n; i++)
        cin >> v1[i].x >> v1[i].y;
    for (int i = 0; i < m; i++)
        cin >> v2[i].x >> v2[i].y;
    
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((v1[i].x - v2[j].x) * (v1[i].x - v2[j].x) + (v1[i].y - v2[j].y) * (v1[i].y - v2[j].y) >= ans)
                ans = (v1[i].x - v2[j].x) * (v1[i].x - v2[j].x) + (v1[i].y - v2[j].y) * (v1[i].y - v2[j].y);
        }
    }
    
    cout << ans;
}