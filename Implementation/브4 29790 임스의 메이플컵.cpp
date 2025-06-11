#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, u, l;
    cin >> n >> u >> l;

    if (n >= 1000)
    {
        if (u >= 8000 || l >= 260)
            cout << "Very Good";
        else
            cout << "Good";
    }
    else
        cout << "Bad";
}