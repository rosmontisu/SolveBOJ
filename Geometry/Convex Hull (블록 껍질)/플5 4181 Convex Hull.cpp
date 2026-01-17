#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    long long x, y;
};

long long ccw(Point p1, Point p2, Point p3)
{
    return (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y)
         - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

    vector<Point> v;
    for (int i = 0; i < n; i++)
    {
        long long x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'Y')
            v.push_back({ x, y });
    }

    sort(v.begin(), v.end(), [](Point a, Point b)
    {
        if (a.x == b.x)
            return a.y < b.y;
        else
            return a.x < b.x;
    });

    vector<Point> ans;
    
    // lower
    for (int i = 0; i < v.size(); i++)
    {
        while (ans.size() >= 2 && ccw(ans[ans.size() - 2], ans.back(), v[i]) < 0)
            ans.pop_back();

        ans.push_back(v[i]);
    }

    // upper
    int lower = ans.size();
    for (int i = v.size() - 2; i >= 0; i--)
    {
        while (ans.size() > lower && ccw(ans[ans.size() - 2], ans.back(), v[i]) < 0)
            ans.pop_back();

        ans.push_back(v[i]);
    }

    ans.pop_back();

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].x << ' ' << ans[i].y << '\n';


    return 0;
}