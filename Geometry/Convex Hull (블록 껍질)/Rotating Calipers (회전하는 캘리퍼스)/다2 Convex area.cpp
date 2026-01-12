// 3차원 블록껍질 공부용 (Quickhull 미사용)

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point
{
    double x, y, z;
};

// 3차원 벡터 외적 - 법선 벡터 (Normal Vector)
Point crossProduct(Point a, Point b)
{
    return { 
        a.y * b.z - a.z * b.y, 
        a.z * b.x - a.x * b.z, 
        a.x * b.y - a.y * b.x 
    };
}

// 3차원 벡터 내적 - 방향 판별 (Dot Product)
double dotProduct(Point a, Point b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

// 3차원 벡터 크기 반환 - 피타고라스 (Magnitude)
double getMagnitude(Point a)
{
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        vector<Point> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i].x >> v[i].y >> v[i].z;

        double answerArea = 0;

        // 브루트포스 풀이
        // 가능한 모든 삼각형 조합 확인
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    // 기준점 i에 대한 두 벡터 생성
                    Point vec1 = { 
                        v[j].x - v[i].x, 
                        v[j].y - v[i].y, 
                        v[j].z - v[i].z 
                    };
                    Point vec2 = { 
                        v[k].x - v[i].x, 
                        v[k].y - v[i].y, 
                        v[k].z - v[i].z 
                    };

                    Point normal = crossProduct(vec1, vec2); // 법선
                    double area2 = getMagnitude(normal); // 넓이 == 외적 벡터의 크기

                    if (area2 == 0) continue; // 예외 - 세 점이 일직선 위에 있음 (면 x)

                    // 검사 - 나머지 모든 점이 평면의 한쪽에만 있어야 함 (평면의 법선 방향 기준)
                    bool hasPlus = false;
                    bool hasMinus = false;

                    for (int m = 0; m < n; m++)
                    {
                        if (m == i || m == j || m == k) continue;

                        Point vec3 = { 
                            v[m].x - v[i].x, 
                            v[m].y - v[i].y, 
                            v[m].z - v[i].z 
                        };
                        double direction = dotProduct(normal, vec3);

                        // 점이 평면의 어느 쪽에 있는지 판별 (양수, 음수) - 이때 실수 오차 고려
                        if (direction > 1e-9) hasPlus = true;
                        if (direction < -1e-9) hasMinus = true;
                    }

                    if (hasPlus && hasMinus) continue; // 예외 - 양쪽에 점이 존재함 (볼록 껍질의 면이 아님)
                    answerArea += area2 / 2.0; // 볼록 껍질의 면 O - 총 넓이에 추가
                }
            }
        }

        // round 반올림은 double 타입 !!!!!!
        cout << (long long)round(answerArea) << '\n';
        cin >> n;
    }

    return 0;
}