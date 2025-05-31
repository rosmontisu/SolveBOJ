#include <iostream>
#include <vector>
#include <string> 
#include <cmath> 
#include <algorithm> 

using namespace std;

struct Point
{
    long long x, y;
};

/*

ccw_value = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1)

P1, P2, P3 세 점의 방향성을 계산하는 함수
p1 첫 번째 점
p2 두 번째 점
p3 세 번째 점
long long:
> 0 : 반시계 방향 (CCW, P3가 벡터 P1->P2의 왼쪽에 있음)
< 0 : 시계 방향 (CW, P3가 벡터 P1->P2의 오른쪽에 있음)
= 0 : 일직선 상 (Collinear)

*/

long long ccw(Point p1, Point p2, Point p3)
{
    // 벡터 P1->P2 와 벡터 P1->P3의 외적의 z성분 계산
    long long result = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    return result;
}

// 콘솔에 점들을 시각적으로 표시
void displayPoints(Point p1, Point p2, Point p3, int width = 20, int height = 10)
{
    vector<string> grid(height, string(width, '.'));

    int origin_x = width / 2;
    int origin_y = height / 2;

    // 축 그리기 
    for (int i = 0; i < height; ++i)
        if (grid[i][origin_x] == '.') grid[i][origin_x] = '|'; // Y축
    for (int j = 0; j < width; ++j)
        if (grid[origin_y][j] == '.') grid[origin_y][j] = '-'; // X축
    if (origin_y >= 0 && origin_y < height && origin_x >= 0 && origin_x < width)
        if (grid[origin_y][origin_x] == '.' || grid[origin_y][origin_x] == '-' || grid[origin_y][origin_x] == '|') grid[origin_y][origin_x] = '+'; // 원점


    // 각 점을 그리드 좌표로 변환하고 표시
    Point points[3] = { p1, p2, p3 };
    char point_char[3] = { '1', '2', '3' };

    for (int i = 0; i < 3; ++i)
    {
        // 입력 좌표를 그리드 좌표로 변환
        // 콘솔 y는 아래로 증가하므로 입력 y를 빼줌
        int grid_x = origin_x + points[i].x;
        int grid_y = origin_y - points[i].y; // Y좌표 반전

        // 그리드 범위 내에 있는지 확인
        if (grid_x >= 0 && grid_x < width && grid_y >= 0 && grid_y < height)
        {
            grid[grid_y][grid_x] = point_char[i]; // 점 위치에 숫자 표시
        }
        else
        {
            // 점이 그리드 밖에 있을 경우 경고 출력
            cout << "에러러: 점 P" << (i + 1) << " (" << points[i].x << "," << points[i].y
                << ")이(가) 그리드 범위를 벗어났습니다" << endl;
        }
    }

    // 그리드 출력 (위에서 아래로)
    cout << "\n--- 시각적 표현 ---" << endl;
    cout << "(그리드 크기: " << width << "x" << height << ", 원점은 중앙 근처)" << endl;
    cout << "(P1='1', P2='2', P3='3')" << endl;
    for (int i = 0; i < height; ++i)
    {
        cout << grid[i] << endl;
    }
    cout << "---------------------------\n" << endl;
}

int main()
{
    Point p1, p2, p3;

    // 사용자로부터 세 점의 좌표 입력 받기
    cout << "점 P1의 좌표 (x y) 입력: ";
    cin >> p1.x >> p1.y;
    cout << "점 P2의 좌표 (x y) 입력: ";
    cin >> p2.x >> p2.y;
    cout << "점 P3의 좌표 (x y) 입력: ";
    cin >> p3.x >> p3.y;

    // CCW 계산
    long long orientation = ccw(p1, p2, p3);

    // 결과 출력 (텍스트)
    cout << "\n--- CCW 계산 결과 ---" << endl;
    cout << "세 점의 방향성 (P1, P2, P3): ";
    if (orientation > 0)
    {
        cout << "반시계 방향 (CCW)" << endl;
        cout << "점 P3는 벡터 P1->P2의 왼쪽에 있습니다." << endl;
    }
    else if (orientation < 0)
    {
        cout << "시계 방향 (CW)" << endl;
        cout << "점 P3는 벡터 P1->P2의 오른쪽에 있습니다." << endl;
    }
    else
    {
        cout << "일직선" << endl;
        cout << "세 점 P1, P2, P3는 일직선 상에 있습니다." << endl;
    }
    cout << "(CCW 값: " << orientation << ")" << endl;
    cout << "-----------------------------" << endl;

    // 시각적 결과 출력 (콘솔 그리드)
    // 그리드 크기는 필요에 따라 조절 가능(코드에서 수정하기)
    displayPoints(p1, p2, p3, 25, 15); // 가로 25, 세로 15 크기 그리드

    return 0;
}