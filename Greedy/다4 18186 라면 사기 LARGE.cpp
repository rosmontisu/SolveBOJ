#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, b, c;
    cin >> n >> b >> c;

    vector<long long> v;
    for (long long i = 0; i < n; i++)
    {
        long long input;
        cin >> input;
        v.push_back(input);
    }

    /*
    1. B
    2. B+C
    3. B+2C

    xxxx예외1 : 3B <= B+2C | 무조건 1개씩 사는게 이득

    그냥 b < c면 되는데?
    1 2

    1. 1
    2. 2 vs 3
    3. 3 vs 5


    1 1
    1. 1
    2. 2 vs 2
    3. 3 vs 3
    */

    long long answer = 0;

    long long erase1 = b;
    long long erase2 = b + c;
    long long erase3 = b + c + c;

    v.push_back(0);
    v.push_back(0);

    // 예외 1
    if (b <= c)
    {
        for (long long i = 0; i < n; i++)
        {
            if (v[i] > 0)
                answer += v[i] * erase1;
        }
        cout << answer << '\n';
        return 0;
    }

    // 예외가 아닌 경우
    for (long long i = 0; i < n; i++)
    {
        if (v[i] > 0)
        {
            if (v[i + 1] > v[i + 2])
            {
                // 뾰족한 모양, 2번 3번 높이 맞추기
                long long minNum = min(v[i], (v[i + 1] - v[i + 2])); // v1, v2-v3높이차
                v[i] -= minNum;
                v[i + 1] -= minNum;
                answer += minNum * erase2;

                minNum = min(min(v[i], v[i + 1]), v[i + 2]); // v1, v2, v3
                v[i] -= minNum;
                v[i + 1] -= minNum;
                v[i + 2] -= minNum;
                answer += minNum * erase3;
            }
            else
            {
                // 뾰족하지 않음. 3개씩 바로 지우면 됨
                long long minNum = min(min(v[i], v[i + 1]), v[i + 2]); // v1, v2, v3
                v[i] -= minNum;
                v[i + 1] -= minNum;
                v[i + 2] -= minNum;
                answer += minNum * erase3;

                minNum = min(v[i], v[i + 1]); // v1, v2
                v[i] -= minNum;
                v[i + 1] -= minNum;
                answer += minNum * erase2;
            }

            answer += v[i] * erase1;
            v[i] = 0;
        }
    }

    cout << answer << '\n';
}