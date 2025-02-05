#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int a, b;
    cin >> a; cin >> b;
    int sum = a + b;
    int ans = 0;
    while (sum > 0)
    {
        ans++;
        sum /= 10;
    }

    cout << ans;
}
