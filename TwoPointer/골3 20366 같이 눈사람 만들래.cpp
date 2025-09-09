#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n; cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {

        }
    }

    
}