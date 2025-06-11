#include <iostream>
#include <vector>
using namespace std;

pair<int, int> p[3];

#define A p[0]
#define B p[1]
#define C p[2]

#define X first
#define Y second

int main()
{
    for (int i = 0; i < 3; i++)
    {
        int x, y;
        cin >> x >> y;
        p[i].X = x;
        p[i].Y = y;
    }
    
    int ans = (A.X * B.Y + B.X * C.Y + C.X * A.Y 
        - A.Y * B.X - B.Y * C.X - C.Y * A.X);
    
    cout << (ans > 0) - (ans < 0); // 1 0 -1
        
    
}
    
    