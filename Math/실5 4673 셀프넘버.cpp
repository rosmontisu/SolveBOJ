#include <iostream>
using namespace std;

bool dp[10002];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    dp[10000] = true;

    for (int i = 1; i <= 10000; i++)
    {
        if (i < 10)
            dp[i + i] = true;

        else if (i < 100)
            dp[(i % 10) + (i / 10) + i] = true;

        else if (i < 1000)
            dp[(i % 10) + (i / 10 % 10) + (i / 100) + i] = true;

        else
        {
            int tmp = (i % 10) + (i / 10 % 10) + (i / 100 % 10) + (i / 1000) + i;
            if (tmp <= 10000)
                dp[tmp] = true;
        }
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (dp[i] == false)
            cout << i << '\n';
    }
}
