#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[5];
    int sum = 0;
    
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i = 0; i < 5; i++)
    {
        int tmp = i;
        for (int j = i + 1; j < 5; j++)
            if (arr[tmp] >= arr[j]) tmp = j;
        swap(arr[i], arr[tmp]);
    }

    cout << sum/5 << '\n';
    cout << arr[2];
    
}