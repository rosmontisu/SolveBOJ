// 이전 코드

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

vector<pair<int, int>> v;

bool CCW(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    return (a.X * b.Y + b.X * c.Y + c.X * a.Y
      - a.Y * b.X - b.Y * c.X - c.Y * a.X) > 0; // 반시계 방향
}
/*
모노톤 체인 Monotone Chain
*/

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({ x, y });
    }

    sort(v.begin(), v.end()); // x 좌표 우선 오름차순 정렬

    // 윗껍질 구하기
    stack<pair<int, int>> stk;

    // ccw 최소 조건으로 점 2개를 미리 넣기
    stk.push(v[0]); 
    stk.push(v[1]); 
    for (int i = 2; i < n; i++)
    {
        while (stk.size() >= 2)
        {
            pair<int, int> a, b, c;
        
            c = v[i];
            b = stk.top(); stk.pop();
            a = stk.top(); 

            // 시계 방향으로 꺾일때
            if(CCW(a, b, c))
            {
                stk.push(b); // 원상복귀
                //stk.push(c); // 새 좌표 추가
                break;
            }
        }
        stk.push(v[i]); // 새 좌표 추가
    }
    int answer = 0;
    answer += stk.size(); // 윗껍질의 수



    // 아래껍질 구하기 - 반대편부터 역순으로 검사
    stack<pair<int, int>> stk2;
    stk2.push(v[n - 1]); // 반대편 기준점
    stk2.push(v[n - 2]); // 기준점 다음 점
    for (int i = n - 3; i >= 0; i--)
    {
        while (stk2.size() >= 2)
        {
            pair<int, int> a, b, c;
        
            c = v[i];
            b = stk2.top(); stk2.pop();
            a = stk2.top(); 

            // 반시계 방향으로 꺾일때
            if(CCW(a, b, c))
            {
                stk2.push(b); // 원상복귀
                //stk2.push(c); // 새 좌표 추가
                break;
            }
        }
        stk2.push(v[i]); // 새 좌표 추가
    }
    answer += stk2.size();
    answer -= 2;

    // 이게 맞?나
    if (answer < 3) cout << 3;
    else cout << answer;
}