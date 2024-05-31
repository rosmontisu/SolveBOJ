#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;

    int c;
    for (int i = 0; i < t; i++)
    {
        cin >> c;
        cout << c/25 << ' '; c %= 25;
        cout << c/10 << ' '; c %= 10;
        cout << c/5 << ' '; c%= 5;
        cout << c/1 << ' ' << '\n';
    }

    // 4개 공백 출력
    // 쿼터 다임 니켈 페니
    // 25 10 5 1
}