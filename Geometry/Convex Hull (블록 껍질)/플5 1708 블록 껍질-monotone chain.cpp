#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    long long x, y;
};

// 신발끈 공식 (구)
long long ccw(Point p1, Point p2, Point p3)
{
    // 세 점 P1, P2, P3로 이루어진 삼각형의 넓이
    return (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y)
         - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}

// 모노톤 체인 Monotone Chain
int main()
{
    int n; cin >> n;

    vector<Point> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].x >> v[i].y;


    // 좌표 오름차순
    sort(v.begin(), v.end(), [](Point a, Point b)
    {
        if (a.x == b.x)
            return a.y < b.y;
        else
            return a.x < b.x;
    });

    if (n <= 2)
    {
        cout << n;
        return 0;
    }

    vector<Point> hull;
    
    // lower hull
    for (int i = 0; i < n; i++)
    {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), v[i]) <= 0)
            hull.pop_back();

        hull.push_back(v[i]);
    }

    // upper hull - 역순
    int lower = hull.size();
    for (int i = n - 2; i >= 0; i--)
    {
        while (hull.size() > lower && ccw(hull[hull.size() - 2], hull.back(), v[i]) <= 0)
            hull.pop_back();

        hull.push_back(v[i]);
    }

    // 시작점, 마지막점 중복 1개 제거
    cout << hull.size() - 1;

    return 0;
}