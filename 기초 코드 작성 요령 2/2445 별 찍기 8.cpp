#include <iostream>
using namespace std;
int n;


void topStar(int i)
{
    for (int j = n-i-1; j < n; j++)
        cout << '*';
}
void topSpace(int i)
{
    for (int j = i + 1; j < n; j++)
        cout << ' ';
}

void underStar(int i)
{
    for (int j = i; j < n-1; j++)
        cout << '*';
}
void underSpace(int i)
{
    for (int j = n-i-1; j < n; j++)
        cout << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> n;

    // 위부터 중앙까지
    for (int i = 0; i < n; i++)
    {
        topStar(i);
        topSpace(i);
        topSpace(i);
        topStar(i);
        cout << '\n';
    }

    // 아래만
    for (int i = 0; i < n-1; i++)
    {
        underStar(i);
        underSpace(i);
        underSpace(i);
        underStar(i);
        cout << '\n';
    }

    return 0;
}