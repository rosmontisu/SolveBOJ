#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;

    int max_X = INT_MIN;
    int max_Y = INT_MIN;
    int min_X = INT_MAX;
    int min_Y = INT_MAX;
    /*
    max 값을 0으로 초기화할 경우 모든 입력값이 음수일때 오답이 뜬다.
    INT_MIN 또는 입력 최소값인 -10000으로 수정해줘야한다.
    */

    cin >> n;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    while(n--)
    {
        int a, b;
        cin >> a >> b;

        if (max_X < a) max_X = a;
        if (min_X > a) min_X = a;

        if (max_Y < b) max_Y = b;
        if (min_Y > b) min_Y = b;
    }

    cout << (max_X-min_X)*(max_Y-min_Y);
}