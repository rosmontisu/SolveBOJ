#include <iostream>
using namespace std;
int main()
{
    while(1)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if ((a+b+c) == 0)
            return 0;
        
        if ((a+b)<=c || (a+c)<=b || (b+c)<=a)
            cout << "Invalid\n";
        else if (a == b && b == c)
            cout << "Equilateral\n";
        else if (a == b || b == c || a == c)
            cout << "Isosceles\n";
        else
            cout << "Scalene\n";
    }
}