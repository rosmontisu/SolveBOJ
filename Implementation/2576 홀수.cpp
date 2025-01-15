#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int arr[7];
    int min = INT_MAX;
    int sum = -1;
    for (int i = 0; i < 7; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2)
        {
            sum += arr[i];
            if (min > arr[i])
                min = arr[i];
        }
    }
    
    if (sum == -1)
        cout << -1;
    else
        cout << sum << '\n' << min;
    return 0;
}