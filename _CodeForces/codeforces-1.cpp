#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int ones = 0;
        int zeros = 0;
        for (char c : s)
            if (c == '1')
                ones++;

        zeros = n - ones;

        cout << ones * (n-1) + zeros << '\n';
    }

    return 0;
}
/*
길이가 n인 문자열 s

1번부터 n번까지 문자를 뒤집어서 다시 n개 생성

*/