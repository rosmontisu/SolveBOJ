/*

int 타입 문제였네요

1. int -> long long 타입 문제
- 절대값이 40000이므로... ccw에서 int형을 넘기는 문제가 발생
--


2. 시작점 찾기전 정렬 문제
- 기존 정렬 x오름차순 우선
(수정)-> y오름차순 && y가 같을때는 x오름차순
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second
#define int long long

vector<pair<int, int>> v;
long long CCW(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    return (a.X * b.Y + b.X * c.Y + c.X * a.Y
      - a.Y * b.X - b.Y * c.X - c.Y * a.X);
}

//************************************************************************* */
// 설마 좌표 정렬에서 문제????
bool CompareByYPos(pair<int, int> a, pair<int, int> b)
{
    if(a.Y == b.Y)
        return a.X < b.X; // 같으면 x오름차순
    return a.Y < b.Y; // y오름차순
}

// 각도기준 sort용 비교 함수 
bool CompareByAngle(pair<int, int> a, pair<int, int> b)
{
    int tmp = CCW(v[0], a, b);

    if (tmp) 
        return tmp > 0; // 반시계
    else if (a.Y != b.Y)  
        return a.Y < b.Y; // 시계 방향이면, y 오름차순
    else
        return a.X < b.X; // 시계 방향이고, y 가 같다면 x 오름차순
}

/*
컨벡스홀 알고리즘 
- 그라함 스캔 (Graham Scan)
*/
#undef int long long
int main()
{
    #define int long long
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(v.begin(), v.end(), CompareByYPos); // 정렬 수정해보기

    sort(v.begin()+1, v.end(), CompareByAngle); // 기준 좌표 다음 부터 각도 순 정렬

    stack<pair<int, int>> stk;
    stk.push(v[0]);
    stk.push(v[1]);

    // 그라함 스캔
    // ccw가 양수로 나오게 서치 (음수면 기존 좌표를 pop하고 양수를 찾을때까지 계속 검사)
    for (int i = 2; i < n; i++)
    {
        while (stk.size() >= 2)
        {
            pair<int, int> a, b, c;
            c = v[i];
            b = stk.top(); stk.pop();
            a = stk.top();
            if (CCW(a, b, c) > 0 && stk.size())
            {
                stk.push(b);
                break;
            }
        }
        stk.push(v[i]);
    }

    cout << stk.size();
}