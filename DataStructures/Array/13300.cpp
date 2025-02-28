#include <iostream>
using namespace std;

int arr[2][7]; // 성별-학년

int main()
{
    int n, k;
    cin >> n >> k;

    int ans = 0;
    while (n--)
    {
        int s, y;
        cin >> s >> y;
        arr[s][y]++;
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            ans += arr[i][j] / k;
            if (arr[i][j] % k > 0) ans++; // 나머지가 있으면 방 1개 추가 
        }
    }

    cout << ans;
}

// fragmentation EBP-ESP 중간제공 EBX 