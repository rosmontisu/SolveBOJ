#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int main(void)
{
	int a, b, c;
	cin >> a >> b >> c;

	if (a == 0)
		cout << (c*c) - b;
	else if (b == 0)
		cout << (c*c) - a;
	else if (c == 0)
		cout << sqrt(a+b);
}