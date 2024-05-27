#include <iostream>
using namespace std;

void input()
{
    int M, N;
    cin >> M;
    cin >> N;
    answer(M, N);
}
void answer(int m, int n)
{
    int sum = 0;
    int min = 10001;
    
    int i = 1;
    for (i=1; i*i <= n; i++)
    {
        // 최대 최소 제한
        if (i*i >= m && i*i <= n)
        {
            sum += i*i;
            if (i*i < min)
                min = i*i;
        }
    }
    
    if (sum == 0)
        cout << -1 << endl;
    else
    {
        cout << sum << endl;
        cout << min << endl;
    }
}

int main()
{
    input();
    return 0;
}