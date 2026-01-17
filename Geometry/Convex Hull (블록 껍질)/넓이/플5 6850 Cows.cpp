#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 1708 볼록 껍질 - 모노톤 체인 풀이 이용

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
    ios::sync_with_stdio(false);
    cin.tie(NULL);

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

    // 점이 2개 이하면 면적은 0
    if (n <= 2)
    {
        cout << 0;
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

    // 볼록 껍질의 면적 계산 (신발끈 공식)
    // 모노톤 체인은 시작점이 끝에 다시 포함되므로 (닫힌 다각형)
    // 0부터 size-2까지 순회
    long long areaSum = 0;
    for (int i = 0; i < hull.size() - 1; i++)
    {
        areaSum += (hull[i].x * hull[i + 1].y) - (hull[i].y * hull[i + 1].x);
    }

    // 실제 면적 = |areaSum| / 2
    // ... 면적 / 50
    // (|areaSum| / 2) / 50 = |areaSum| / 100
    cout << abs(areaSum) / 100;

    return 0;
}