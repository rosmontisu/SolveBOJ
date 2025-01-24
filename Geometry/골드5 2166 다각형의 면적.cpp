#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<long double, long double> p[10002]; // long double로 해야 부동소수점 오류가 안남

#define X first
#define Y second

/*
두 벡터의 외적은 2차원 평면에서 평행사변형의 넓이를 구하는 것과 같다
외적의 값이 양수이면 반시계 방향, 음수이면 시계 방향

3차원 공간에서의 외적은 원래 두 벡터에 모두 수직인 벡터를 반환한다

CCW는 두 벡터의 외적을 반환하므로, /2를 하면 삼각형의 넓이가 된다
--> 여기까지가 어제 사용한 CCW의 개념


신발끈 공식? (이전에 사용한 ccw에 abs()/2만 추가하면 된다)
-> 시각적으로 이해된건...
y좌표가 아래로 내려가는 넓이는 더하고, 위로 올라가는 넓이는 뺀다.



// 건빵님 추천 영상 : 블록 껍질 알고리즘
(https://youtu.be/ZzQGZ97ax0k?si=RnW3JA0ecgg2VJnT)
*/
long double CCW(pair<long double, long double> a, pair<long double, long double> b, pair<long double, long double> c)
{
    return (a.X * b.Y + b.X * c.Y + c.X * a.Y
        - a.Y * b.X - b.Y * c.X - c.Y * a.X) / 2.0; // 삼각형의 넓이, /2 추가
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long double x, y;
        cin >> x >> y;
        p[i] = { x, y };
    }

    long double sum = 0;
    for (int i = 1; i < n - 1; i++)
    {
        // 이때 기준이 되는 점이 필요하니 p[0]으로 고정
        sum += CCW(p[0], p[i], p[i + 1]);
    }

    cout << fixed;  // 소수점 고정
    cout.precision(1); // 1자리로 고정
    cout << abs(sum) << '\n';
}

