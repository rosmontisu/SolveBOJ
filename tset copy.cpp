#include <iostream>
#include <string>
using namespace std;

int room[1000010];

int main()
{
    int n;
    int b, c;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> room[i];

    cin >> b >> c;

    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        room[i] -= b;
        if (b <= 0)
            answer += 1;
        else if (room[i] % c == 0)
            answer += room[i] / c + 1;
        else
            answer += room[i] / c + 2;
    }

    cout << answer;
}