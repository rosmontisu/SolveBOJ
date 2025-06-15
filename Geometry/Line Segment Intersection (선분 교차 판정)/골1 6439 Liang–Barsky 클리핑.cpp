/*
Liang-Barsky의 클리핑 알고리즘 으로도 풀 수 있다고 한다.
- 기록용 코드
https://en.wikipedia.org/wiki/Liang%E2%80%93Barsky_algorithm
https://www.geeksforgeeks.org/computer-graphics/liang-barsky-algorithm/
- 그래픽스
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 선분 클리핑 함수
// p: p[0]=-dx, p[1]=dx, p[2]=-dy, p[3]=dy
// q: q[0]=x_start-x_min, q[1]=x_max-x_start, q[2]=y_start-y_min, q[3]=y_max-y_start
// t_enter, t_exit: 선분이 사각형 내부에 머무는 t의 범위 [t_enter, t_exit]
bool clip(double p, double q, double& t_enter, double& t_exit) 
{
    // 선이 경계와 평행한 경우
    if (p == 0) 
    {
        // 선이 경계 바깥에 있으면 교차하지 않음
        if (q < 0) 
            return false;
    } 
    else 
    {
        double t = q / p;
        if (p < 0) 
        {
            // 선이 경계 안으로 들어오는 경우 (p < 0)
            // 여러 들어오는 지점 중 가장 나중의 t값을 선택
            t_enter = max(t_enter, t);
        } 
        else 
        {
            // 선이 경계 밖으로 나가는 경우 (p > 0)
            // 여러 나가는 지점 중 가장 처음의 t값을 선택
            t_exit = min(t_exit, t);
        }
    }
    return true;
}


int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) 
    {
        double xs, ys, xe, ye; // 선분 시작점, 끝점
        double r1x, r1y, r2x, r2y; // 직사각형 두 꼭짓점

        cin >> xs >> ys >> xe >> ye >> r1x >> r1y >> r2x >> r2y;

        double xmin = min(r1x, r2x);
        double xmax = max(r1x, r2x);
        double ymin = min(r1y, r2y);
        double ymax = max(r1y, r2y);

        double dx = xe - xs;
        double dy = ye - ys;

        double t_enter = 0.0;
        double t_exit = 1.0;

        bool intersects = true;

        // 1. 왼쪽 경계와 클리핑
        if (!clip(-dx, xs - xmin, t_enter, t_exit)) intersects = false;
        // 2. 오른쪽 경계와 클리핑
        if (intersects && !clip(dx, xmax - xs, t_enter, t_exit)) intersects = false;
        // 3. 아래쪽 경계와 클리핑
        if (intersects && !clip(-dy, ys - ymin, t_enter, t_exit)) intersects = false;
        // 4. 위쪽 경계와 클리핑
        if (intersects && !clip(dy, ymax - ys, t_enter, t_exit)) intersects = false;

        if (intersects && t_enter > t_exit) 
            intersects = false;
        

        if (intersects) 
            cout << "T\n";
        else 
            cout << "F\n";
        
    }

    return 0;
}