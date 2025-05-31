#include <iostream>
#include <vector>
using namespace std;

// 이전에 선분 그룹 문제에서 
// 세 점이 일직선 위에 있는 경우 (예외처리) 가 필요 없는 문제

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