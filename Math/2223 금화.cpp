#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // t 제한시간
    // x 줍는 양

    // d dist
    // s 1t당 이동거리
    // m 몬스터의 수

    // 몬스터가 도달하는데 걸리는 턴
    // (d%s == 0) ? d/s : d/s+1;
    int t, x, m;
    
    cin >> t >> x >> m;

    int answer = 1e9;

    for (int i = 0; i < m; i++)
    {
        int d, s;
        cin >> d >> s;

        // 도착하는데 걸리는 시간
        answer = min(answer, (d-1) / s);
        //int temp = (d%s == 0) ? d/s : d/s+1;
    }
    
    // 시작부터 잡힌다면?
    if (answer == 0) cout << answer * x;

    // 일반적인 상황
    else if (t > answer) cout << (answer + (t-answer)/2) * x;

    // 몬스터가 시간안에 올 수 없다면?
    else cout << t*x;
}