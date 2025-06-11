#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// 직선의 방정식으로 교차점 (연립) 찾으면 될거같은 문제
// ax + by + c = 0;
// (y1-y2)x + (x2-x1)y + (x1y2 - x2y1) = 0
// (y3-y4)x + (x4-x3)y + (x3y4 - x4y3) = 0

// 이항 후 연립
// (y1-y2)x + (x2-x1)y  = (x2y1 - x1y2)
// (y3-y4)x + (x4-x3)y  = (x4y3 - x3y4)

// 행렬
// |(y1-y2) (x2-x1) * (x)| = (x2y1 - x1y2)
// |(y3-y4) (x4-x3)   (y)|   (x4y3 - x3y4)

// 보기 편하게 기호로 바꾸고
// (A1 B1) * (x) = (C1)
// (A2 B2)   (y)   (C2)

// 행렬식 
// 참고) D = 0 : 두 직선이 평행 (기울기가 같으므로)
// --> 이부분 헷갈리면 직접 y = mx + c 꼴로 만들어보기
// D = (A1 * B2) - (B1 * A2)

// x y 에 대한 행렬식
// Dx = (C1*B2) - (C2*B1)
// Dy = (A1*C2) - (A2*C1)

// 이산수학 선대에서 배운 크래머공식으로 (정확도는 떨어지지만..) 구하면
// x = Dx/D
// y = Dy/D
void getPoint(pair<pair<int, int>, pair<int, int>> l1, pair<pair<int, int>, pair<int, int>> l2)
{ 
    pair<int, int> a = l1.first;
    pair<int, int> b = l1.second;
    pair<int, int> c = l2.first;
    pair<int, int> d = l2.second;

    long long x1 = a.first, y1 = a.second;
    long long x2 = b.first, y2 = b.second;
    long long x3 = c.first, y3 = c.second;
    long long x4 = d.first, y4 = d.second;

    long long A1 = y1 - y2;
    long long B1 = x2 - x1;
    long long C1 = x2 * y1 - x1 * y2;

    long long A2 = y3 - y4;
    long long B2 = x4 - x3;
    long long C2 = x4 * y3 - x3 * y4;

	long long D = A1 * B2 - A2 * B1; // 계수 행렬식
	long long Dx = C1 * B2 - C2 * B1; // x에 대한 행렬식
    long long Dy = A1 * C2 - A2 * C1; // y에 대한 행렬식

    // isCross 안에서 처리
    // 예외처리 1) 겹치는데, 한 점에서 겹치는게 아닌 경우 
    // if (D == 0) // 기울기가 같으니까, 겹치지만 한 점이 아니라 서로 포개지는 상황
    //    return;

    double x = (double)Dx / D;
    double y = (double)Dy / D;
    // cout 소수점 자리수 조정 필요!!!!! 
    cout << fixed;
    cout.precision(16); // 8byte 실수 - 15자리정도 https://learn.microsoft.com/ko-kr/cpp/cpp/data-type-ranges?view=msvc-170
    cout << x << ' ' << y;
}

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

void isCross(pair<pair<int, int>, pair<int, int>> l1, pair<pair<int, int>, pair<int, int>> l2)
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
        if (max(a, c) < min(b, d))
        {
            cout << 1 << '\n';
            return;
        }
        else if (max(a, c) == min(b, d)) // 예외 처리 2) 동일 직선 위에 있는데, 딱 한 점에서만 겹치는 경우
        {
            cout << 1 << '\n';
            cout << max(a, c).first << ' ' << max(a, c).second; // 겹치는 점을 연산 없이 바로 출력
            return;
        }
        else
        {
            cout << 0;
            return;
        }
    }

    // 일반적인 경우
    if (abc * abd <= 0 && cda * cdb <= 0) 
    {
        cout << 1 << '\n';
        getPoint(l1, l2);
        return;
    }
    else
    {
        cout << 0;
        return;
    }
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

    isCross(lines[0], lines[1]);

    return 0;
}