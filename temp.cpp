#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a, b, c;

    cin >> a;
    cin >> b;
    cin >> c;
    cout << a + b - c << '\n';
    
    string s = to_string(a) + to_string(b);

    cout << stoi(s) - c;
}