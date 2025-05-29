#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
    priority_queue<int, vector<int>, greater<int>> pq_rooms;
    
    while (n--)
    {
        int s, t;
        cin >> s >> t;
        
        pq.push({ s, t });
    }
    
    // 강의가 끝나는 시간을 기준으로 room을 대여, 만약 room에 기록된 끝나는 시간보다 빨리 강의가 시작되야 하는경우?
    // 새로운 room을 끝나는 시간을 기준으로 추가로 대여
    
    // 초기화
    auto pair = pq.top(); pq.pop();
    pq_rooms.push(pair.second);
    
    while(!pq.empty())
    {
        pair = pq.top(); pq.pop();
        // 새 강의실을 대여
        if (pair.first < pq_rooms.top())
        {
            pq_rooms.push(pair.second);
        }
        // 원래 강의실에 종료 시간만 변경
        else
        {
            pq_rooms.pop();
            pq_rooms.push(pair.second);
        }
    }
    
    cout << pq_rooms.size();
    
    return 0;
    
}