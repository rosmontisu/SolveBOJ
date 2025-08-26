#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1, -1);
    vector<int> s(n+1, -1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    // 구간합의 값이 특정한 값이 나오는 모든 개수
    // s[r] - s[l - 1] = k
    // s[l - 1] = s[r] - k


}