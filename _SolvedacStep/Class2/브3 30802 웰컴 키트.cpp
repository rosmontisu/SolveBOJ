#include <iostream>
using namespace std;

int main()
{
    int n;
    int arr[6];
    int t, p; // t묶음으로만 주문 가능, p묶음or1개로만 주문 가능

    cin >> n;
    for (int i = 0; i < 6; i++) cin >> arr[i];
    cin >> t >> p;

    int sum = 0;
    for (int i = 0; i < 6; i++)
        sum += (arr[i]%t == 0 ? (arr[i] / t) : (arr[i] / t + 1));

    cout << sum << '\n';
    cout << n/p << ' ' << n%p;
}