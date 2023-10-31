#include <iostream>

using namespace std;

int arr[30];
int main(void)
{
    string str;
    cin >> str;
    // a == 97
    
    for (int i = 0; i < str.length(); i++)
    {
        arr[str[i]-97] += 1;
    }
    
    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << ' ';
    }
}
