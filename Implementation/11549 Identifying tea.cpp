#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, i, result = 0; 
    cin >> t;
    i = 5;
    while(i--)
    {
        int num;
        cin >> num;
        if (num == t) result++;
    }
    cout << result;
}