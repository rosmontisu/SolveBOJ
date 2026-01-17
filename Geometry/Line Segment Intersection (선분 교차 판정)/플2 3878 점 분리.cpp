// 기하 문제 (ccw, convex hull 등의 문제를 풀기 위한 템플릿 코드)
// 사용 알고리즘은 monotone chain (O(n log n))
// 추가로 벡터 외적 함수와 ccw 함수 포함

// 2025-01-16 선분 교차 판정 (볼록 껍질이 겹치는 경우, 점이 내부에 있는 경우) 템플릿에 추가

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    long long x, y;

    // 좌표 정렬용 연산자 오버로딩 추가
    bool operator < (const Point& p) const 
    {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    bool operator <= (const Point& p) const 
    {
        if (x != p.x) return x < p.x;
        return y <= p.y;
    }
    bool operator == (const Point& p) const
    {
        return (x == p.x) && (y == p.y);
    }

    Point operator - (const Point& p) const 
    {
        return { x - p.x, y - p.y };
    }
};

long long crossProduct(Point a, Point b) 
{
    return a.x * b.y - a.y * b.x;
}

// 신발끈 공식 (개선)
// 세 점 P1, P2, P3로 이루어진 삼각형의 넓이
long long ccw(Point p1, Point p2, Point p3)
{
    return crossProduct(p2 - p1, p3 - p2);
}

// monotone chain
vector<Point> getConvexHull(vector<Point> points) 
{
    int n = points.size();
    if (n <= 2) return points;

    sort(points.begin(), points.end());

    vector<Point> hull;
    
    // lower hull
    for (int i = 0; i < n; i++) 
    {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), points[i]) <= 0) 
            hull.pop_back();
        hull.push_back(points[i]);
    }

    // upper hull - 역순
    int lower = hull.size();
    for (int i = n - 2; i >= 0; i--) 
    {
        while (hull.size() > lower && ccw(hull[hull.size() - 2], hull.back(), points[i]) <= 0) 
            hull.pop_back();
        hull.push_back(points[i]);
    }

    hull.pop_back(); 

    return hull;
}

// 선분 교차 판정 - (17387 선분 교차 2 함수화)
bool isCross(Point a, Point b, Point c, Point d)
{
    long long abc = ccw(a, b, c);
    long long abd = ccw(a, b, d);
    long long cda = ccw(c, d, a);
    long long cdb = ccw(c, d, b);

    // 모든 점이 직선 위에 있다면 
    if (abc == 0 && abd == 0 && cda == 0 && cdb == 0)
    {
        // 계산이 용이하게 점 a와 점 c가 좌하귀로 가도록 정렬
        if (b < a) swap(a, b);
        if (d < c) swap(c, d);

        // 겹침 (항상 그림 그려보기, 일직선으로 점이 a b c d 있을때 b d 에 있는 점을 찾는다 생각하기)
        if (max(a, c) <= min(b, d))
            return true;
        else
            return false;
    }

    // 일반적인 경우
    if (abc * abd <= 0 && cda * cdb <= 0) 
        return true;
    else
        return false;
}

// 점이 블록 껍질 안에 있는 경우도 판정해야됨!!!!
bool isInside(vector<Point> hull, Point p)
{
    // 점이 1개
    if (hull.size() == 1) 
        return hull[0] == p;
    
    // 점이 2개 (선분)
    if (hull.size() == 2) 
    {
        return (ccw(hull[0], hull[1], p) == 0) && // 0, 1, p가 일직선 상에 있고
        ((min(hull[0], hull[1]) <= p) && (p <= max(hull[0], hull[1]))); // 0, 1 사이에 p가 있어야 함
    }

    // 점이 3개 이상 (다각형)
    // 0, 1, p 가 반시계 방향(ccw > 0) 이어야 함
    for (int i = 0; i < hull.size(); i++)
    {
        int next = (i + 1) % hull.size();
        if (ccw(hull[i], hull[next], p) < 0) return false;
    }
    return true;
}

int main() 
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; // 검,흰
        cin >> n >> m;

        vector<Point> v1(n);
        vector<Point> v2(m);

        for (int i = 0; i < n; i++)
            cin >> v1[i].x >> v1[i].y;
        for (int i = 0; i < m; i++)
            cin >> v2[i].x >> v2[i].y;

        // 두 블록껍질이 서로 겹치지 않으면, 직선을 긋는게 가능
        vector<Point> hull1 = getConvexHull(v1);
        vector<Point> hull2 = getConvexHull(v2);

        // 두 블록껍질이 겹치는지 모든 변을 검사
        bool flag = true;
        for (int i = 0; i < hull1.size(); i++)
        {
            for (int j = 0; j < hull2.size(); j++)
            {
                // 1<->2 선분, 2<->3 선분 ...
                Point p1 = hull1[i];
                Point p2 = hull1[(i + 1) % hull1.size()];
                Point p3 = hull2[j];
                Point p4 = hull2[(j + 1) % hull2.size()];

                if (isCross(p1, p2, p3, p4)) 
                {
                    flag = false;
                    break;
                }
            }
        }

        // 상대 블록껍질에 점이 들어가는지 검사
        for (auto p : hull1) 
            if (isInside(hull2, p)) 
                flag = false;
        for (auto p : hull2) 
            if (isInside(hull1, p)) 
                flag = false;

        if (flag) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}