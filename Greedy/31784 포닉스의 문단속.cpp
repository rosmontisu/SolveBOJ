#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, k;
    string str;

    // 길이 n, 횟수 k
    cin >> n >> k;
    cin >> str;

    // 앞쪽 다이얼부터 A로 돌리기
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'A') continue; // 이미 A면 다음 다이얼로

        if (k == 0) break; // 돌릴수없다면 중단

        // 다이얼을 A까지 돌립니다.
        int goToA = ('Z' - str[i] + 1);
        if (goToA <= k)
        {
            k -= goToA;
            str[i] = 'A';
        }
    }

    // 뒤쪽 다이얼 부터 Z에 가깝게 돌리기
    for (int i = n-1; i >= 0 && k > 0; i--)
    {
        while(str[i] != 'Z' && k > 0)
        {
            str[i] += 1;
            k--;
        }
    }
    cout << str;
}

/*
// 개선 코드 1
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, k;
    string str;

    // 길이 n, 횟수 k
    cin >> n >> k;
    cin >> str;

    // 최대한 A로 돌리기
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'A') continue; // 이미 A면 다음 다이얼로

        if (k == 0) break; // 돌릴수없다면 중단

        int goToA = 'Z' - str[i] + 1;
        if  goToA <= k)
        {
            k -= goToA;
            str[i] = 'A';
        }
    }

    // 뒤에서 부터 남은 k를 처리
    for (int i = n-1; i >= 0 && k > 0; i--)
    {
        if (str[i] != 'Z') // Z가 아닐 때만 변환
        {
            int increaseToZ = min(k, 'Z' - str[i]);
            str[i] += increaseToZ;
            k -= increaseToZ;
        }
    }

    cout << str;
}
*/