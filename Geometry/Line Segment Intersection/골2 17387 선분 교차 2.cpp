#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// 이번엔 예외처리 - 점 3개가 직선 위에 있는 경우 구현해보자

vector<pair<pair<int, int>, pair<int, int>>> lines;

long long ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    long long val = 
    ((long long)a.first * b.second + (long long)b.first * c.second + (long long)c.first * a.second)
    - ((long long)b.first * a.second + (long long)c.first * b.second + (long long)a.first * c.second);

    if (val > 0) return 1; // ccw
    else if (val < 0) return -1; // cw
    else return 0;
}

bool isCross(pair<pair<int, int>, pair<int, int>> l1, pair<pair<int, int>, pair<int, int>> l2)
{
    pair<int, int> a = l1.first;
    pair<int, int> b = l1.second;
    pair<int, int> c = l2.first;
    pair<int, int> d = l2.second;

    long long abc = ccw(a, b, c);
    long long abd = ccw(a, b, d);
    long long cda = ccw(c, d, a);
    long long cdb = ccw(c, d, b);

    // 모든 점이 직선 위에 있다면 
    if (abc == 0 && abd == 0 && cda == 0 && cdb == 0)
    {
        // 계산이 용이하게 점 a와 점 c가 좌하귀로 가도록 정렬
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    lines.push_back({{a, b}, {c, d}});

    cin >> a >> b >> c >> d;
    lines.push_back({{a, b}, {c, d}});

    if (isCross(lines[0], lines[1]))
        cout << 1;
    else 
        cout << 0;
}