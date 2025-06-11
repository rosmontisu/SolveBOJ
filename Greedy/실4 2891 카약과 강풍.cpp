#include <iostream>
using namespace std;

bool broken[15];
bool spare[15];
int sum = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s, r;
    cin >> n >> s >> r;
    
    int tmp;
    for (int i = 0; i < s; i++)
    {
        cin >> tmp;
        broken[tmp] = true;
    }

    for (int i = 0; i < r; i++)
    {
        cin >> tmp;
        spare[tmp] = true;
    }
    
    // 본인의 예비용 카약으로 대체
    for (int i = 1; i <= n; i++)
    {
        if (broken[i] && spare[i])
        {
            broken[i] = false;
            spare[i] = false;
        }
    }

    // 옆팀한테 카약 빌려주기
    for (int i = 1; i <= n; i++)
    {
        if (spare[i])
        {
            if (i > 1 && broken[i-1])
                broken[i-1] = false;
            else if (i < n && broken[i+1])
                broken[i+1] = false;
        }
    }

    // 출발하지 못하는 팀의 수
    for (int i = 1; i <= n; i++)
        if (broken[i])
            sum++;


    cout << sum;
    return 0;
}
