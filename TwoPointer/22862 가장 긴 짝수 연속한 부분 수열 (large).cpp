#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000001];

int main()
{
    int n, k;
    cin >> n >> k; // 길이, 삭제기회

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    // 짝수로만 이루어진 부분수열 구하기

    // ed가 짝수 발견시 k감소 ans증가
    // st가 짝수 발견시 k증가 (현재)ans 감소

    int st = 1;
    int ed = 1;
    int ans = 0;
    int length = 0;

    while(st <= ed && ed <= n)
    {
        // 짝수, 계속 진행
        if (arr[ed]%2 == 0)
        {
            length++;
            ed++;
            ans = max(ans, length);
        }
        // 홀수, 제거 가능, 계속 진행
        else if (k > 0)
        {
            k--;
            ed++;
        }
        // 홀수, 제거 불가, 길이 줄이기
        else
        {
            if (arr[st]%2 != 0)
                k++;
            else
                length--;
            st++;
        }
    }

    cout << ans;
}