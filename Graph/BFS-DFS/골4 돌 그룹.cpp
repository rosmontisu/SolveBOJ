#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <set>

using namespace std;

int main() 
{
    int a, b, c;
    cin >> a >> b >> c;

    // 3의 배수가 아니면 애초에 불가능함
    if ((a + b + c) % 3 != 0) 
    {
        cout << 0;
        return 0;
    }

    set<tuple<int, int, int>> visit; 
    queue<tuple<int, int, int>> q;     
    q.push({ a, b, c });

    while (!q.empty()) 
    {
        auto [x, y, z] = q.front();
        q.pop();


        // 1. x == y == z 의 경우를 찾아낸 경우
        if (x == y && y == z) 
        {
            cout << 1;
            return 0;
        }

        // x ≤ y ≤ z 순 정렬
        int arr[3] = {x, y, z};
        sort(arr, arr + 3);
        x = arr[0];
        y = arr[1];
        z = arr[2];

        if (visit.count({ x, y, z }) > 0) continue;
        visit.insert({ x, y, z });

        // 가능한 이동 상태를 큐에 추가
        q.push({ x + x, y - x, z }); // X를 두 배로, Y에서 X를 뺌
        q.push({ x, y + y, z - y }); // Y를 두 배로, Z에서 Y를 뺌
        q.push({ x + x, y, z - x }); // X를 두 배로, Z에서 X를 뺌
    }
    
    // 2. x == y == z 의 경우를 못찾은 경우
    cout << 0;
    return 0; 
}