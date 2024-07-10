#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    long long temp = 1;
    long long result = 1;

    while(true)
    {
        if (temp * 2 <= n)
            temp *= 2;
        else if (temp < n)
        {
            cout << result + 1;
            return 0;
        }
        else
        {
            cout << result;
            return 0;
        }
        result++;
    }
}