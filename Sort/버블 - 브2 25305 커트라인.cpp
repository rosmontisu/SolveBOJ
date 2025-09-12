#include <iostream>
#include <vector>
using namespace std;

// 내림차순 버블정렬
void bsort(vector<int>& v)
{
    int m = v.size();
    for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < m - 1 - i; j++)
            if (v[j] < v[j + 1])
                swap(v[j], v[j + 1]);
}

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    bsort(v);
    
    cout << v[k - 1];
}