// 문제 이해를 잘못해서 한참 걸린 문제..
// - 다시 풀때는 꼭 그림그려서 끼워맞춰보기..
// - https://media.discordapp.net/attachments/1080909625454506024/1378024988929687573/image.png?ex=683b1947&is=6839c7c7&hm=e32ecfb1bffca548c244a615edef7c7632af122e82a4fe5da3a7f749fd676774&=&format=webp&quality=lossless
// T1 - { 1, 3 } <-> { 6, 9 } : 2 + 3

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n; // 센서의 수
    cin >> k; // 집중국
    priority_queue<int, vector<int>, greater<int>> pq; // 센서 min heap 정렬
    
    // 1. 센서 min heap 초기화
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        pq.push(t);
    }

    // 예외처리
    if (k >= n)
    {
        cout << 0;
        return 0;
    }


    // 2. 센서간의 거리 max heap 초기화
    priority_queue<int, vector<int>> pqn; // 센서거리 max heap 정렬
    int cur = pq.top(); pq.pop();
    int nxt;
    while(!pq.empty())
    {
        nxt = pq.top();
        if (nxt - cur > 0)
            pqn.push(nxt-cur);
        cur = nxt; pq.pop();
    }

    // 3. 긴 거리부터 제거, 최대한 적은 거리를 남기는게 목적이므로
    k -= 1; // k - 1 개 보정 (2개부터 거리가 생기니까)
    while(k--) 
        if(!pqn.empty()) pqn.pop();

    
    // 4. 집중국 범위 측정
    int ans = 0;
    while (!pqn.empty())
    {
        ans += pqn.top();
        pqn.pop();
    }

    cout << ans;
}