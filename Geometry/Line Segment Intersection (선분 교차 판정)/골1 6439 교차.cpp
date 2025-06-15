#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

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
        // 계산이 용이하게 스왑
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);

        // 더 작은 점이 큰점을 넘어감 - 겹친다
        return max(a, c) <= min(b, d);
    }

    // 일반적인 경우
    return abc * abd <= 0 && cda * cdb <= 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int ax, ay, bx, by, 
            ux, uy, vx, vy;

        //cin >> ax >> ay >> bx >> by >> ux >> uy >> vx >> vy;
        cin >> ux >> uy >> vx >> vy >> ax >> ay >> bx >> by; // 반대로 받았다..

        // 1. 좌표 정규화 - 반대일수있음
        int min_x = min(ax, bx);
        int max_x = max(ax, bx);
        int min_y = min(ay, by);
        int max_y = max(ay, by);

        pair<pair<int, int>, pair<int, int>> target_line = {{ux, uy}, {vx, vy}};

        // 2. 직사각형의 경계와 교차
        vector<pair<pair<int, int>, pair<int, int>>> lines;
        lines.push_back({{min_x, min_y}, {max_x, min_y}});
        lines.push_back({{max_x, min_y}, {max_x, max_y}});
        lines.push_back({{max_x, max_y}, {min_x, max_y}});
        lines.push_back({{min_x, max_y}, {min_x, min_y}});

        bool isTrue = false;
        for (int i = 0; i < 4; i++)
        {
            if (isCross(target_line, lines[i]))
            {
                isTrue = true;
                break;
            }
        }
        if (isTrue)
        {
            cout << "T\n";
            continue; // 선이 직사각형에 포함되는 경우가 아니므로 컨티뉴
        }
        
        // 3. 직사각형 내부에 포함
        bool u_in = (ux >= min_x && ux <= max_x && 
                        uy >= min_y && uy <= max_y);

        bool v_in = (vx >= min_x && vx <= max_x && 
                        vy >= min_y && vy <= max_y);

        if (u_in && v_in) 
            cout << "T\n";
        else 
            cout << "F\n";
        
    }

    return 0;
}