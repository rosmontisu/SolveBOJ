#include <math.h>
#include <iostream>
using namespace std;

long long Prime(long long n)
{
    long long p = n;
    while (true)
        for (long i = 2; i <= sqrt(p) + 1; i++)
        {
            if (i > sqrt(p))
                return p;
            else if (p % i == 0)
            {
                p++;
                break;
            }
        }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;
        if (n == 1 || n == 0)
            cout << 2 << '\n';
        else
            cout << Prime(n) << '\n';
    }

    return 0;
}