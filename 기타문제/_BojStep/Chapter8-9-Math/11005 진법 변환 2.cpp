#include <iostream>
using namespace std;

char iToZ(int intnum)
{
    if (intnum >= 10)
        return intnum + 'A' - 10;
    else
        return intnum + '0';
}

int main()
{
    int n, b;
    cin >> n >> b;
    char answer[1000];
    int count = 0;

    if (n == 0)
    {
        cout << '0';
        return 0;
    }

    while (n > 0)
    {
        answer[count] = iToZ(n % b);
        n /= b;
        count++;
    }

    for (int i = count - 1; i >= 0; i--)
        cout << answer[i];

}
