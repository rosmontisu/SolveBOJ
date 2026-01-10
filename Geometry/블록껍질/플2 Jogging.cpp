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
        return tmp > 0; // 반시계 (각도 더 큼)
    else if (a.Y != b.Y)  
        return a.Y < b.Y; // 시계 방향이면, y 오름차순
    else
        return a.X < b.X; // 시계 방향이고, y 가 같다면 x 오름차순
}




pair<int, int> point;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {

    }
}