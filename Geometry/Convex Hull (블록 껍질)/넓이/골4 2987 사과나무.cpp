// 기하 문제 (ccw, convex hull 등의 문제를 풀기 위한 템플릿 코드)
// 사용 알고리즘은 monotone chain (O(n log n))
// 추가로 벡터 외적 함수와 ccw 함수 포함

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

int main() 
{
    // 점 P가 있을때 ABP + BCP + CAP == ABC 이면
    // 점P는 삼각형 ABC안에 있다는거임

    Point a, b, c;
    cin >> a.x >> a.y >> 
           b.x >> b.y >> 
           c.x >> c.y;

    int n; cin >> n;
    long long abc = abs(ccw(a, b, c));

    int ans = 0;
    while (n--)
    {
        Point p;
        cin >> p.x >> p.y;
        long long abp = abs(ccw(a, b, p));
        long long bcp = abs(ccw(b, c, p));
        long long cap = abs(ccw(c, a, p));

        if (abc == abp + bcp + cap) ans++;
    }

    cout << fixed << setprecision(1) << abc / 2.0 << '\n';
    cout << ans;
}