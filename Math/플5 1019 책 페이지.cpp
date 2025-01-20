#include <iostream>
using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[12] = {};
    int data[10][10]; // 초기화 값, 미리 연산해 둘예정

    int n;
    cin >> n;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            data[i][j] = 0;


    // 미리 (1,1) 부터 (9,9) 까지의 값을 구하기 
    for (int i = 1; i < 10; i++)
    {
        int temp = i;

        while (true)
        {
            data[i][temp % 10]++;
            if (temp / 10 == 0) break;
            temp /= 10;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int temp = i;

        while (true)
        {
            arr[temp % 10]++;
            if (temp / 10 == 0) break;
            temp /= 10;
        }
    }

    for (int i = 0; i < 10; i++)
        cout << arr[i] << ' ';

}