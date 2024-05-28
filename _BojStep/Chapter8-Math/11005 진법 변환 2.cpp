#include <iostream>
#include <math.h>
#include <string>
using namespace std;

char iToZ(int n)
{
    if (n > 10)
        return n+55;
    else
        return n+'0';
}

int main()
{
    int n, b;
    cin >> n >> b;
    string str = {};

    for (int i = 1; i < b; i++)
    {
        n/=b;
        str[i] = iToZ(n%(int)(pow(b, i)));
    }

    for (int i = b; i > 0; i--)
        cout << str[i];
}