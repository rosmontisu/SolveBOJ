#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    long double a, b, c;
    cin >> a >> b >> c;

    (a*b/c >= a/b*c) ? cout <<(int) (a*b/c) : cout <<(int) (a/b*c);
    
    return 0;
}
