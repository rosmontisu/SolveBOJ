#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    /*
    ax + by = c
    dx + ey = f
    aex + bey = ec
    bdx + bey = bf
-----------------------
    (ae-bd)x = ce - bf
    x = (ce-bf) / (ae-bd)

    ax + by = c
    dx + ey = f
    adx + bdy = cd
    adx + aey = af
    ------------------------
    (bd-ae)y = cd-af
    y = (cd-af)/(bd-ae)

    
    */
    
	int x = (c * e - b * f) / (a * e - b * d);
    int y = (c * d - a * f) / (b * d - a * e);


    cout << x << ' ' << y;
    return 0;
}