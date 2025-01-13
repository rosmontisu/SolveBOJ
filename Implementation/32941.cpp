#include <iostream>
using namespace std;

int main()
{
    // 교실 T개의 정해진 교시

    int t, x, n;
    cin >> t >> x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        bool flag = false;
        for (int j = 0; j < k; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == x)
            {
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            cout << "NO" << '\n';
        }
    }


}