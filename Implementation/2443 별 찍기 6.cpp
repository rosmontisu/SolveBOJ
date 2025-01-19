#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    
    n = (n*2-1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << ' ';
        for (int j = 0; j < n-(i*2); j++)
            cout << '*';
        cout << '\n';
    }
}