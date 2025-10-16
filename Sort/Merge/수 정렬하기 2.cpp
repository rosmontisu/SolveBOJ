#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr(1000001);
vector<int> ans(1000001);

void merge(int l, int r)
{
    int mid = (l + r) / 2;
    
	int cl = l;    // 왼쪽 시작
	int cr = mid + 1; // 오른쪽 시작
	int cnt = l;

	// 비교
	while (cl <= mid && cr <= r)
	{
		if (arr[cl] <= arr[cr])
			ans[cnt++] = arr[cl++];
		else
			ans[cnt++] = arr[cr++];
	}
    
    // 왼쪽 배열에 남음
    while (cl <= mid)
        ans[cnt++] = arr[cl++];
    
    // 오른쪽 배열에 남음
    while (cr <= r)
        ans[cnt++] = arr[cr++];
    
    for (int i = l; i <= r; i++)
        arr[i] = ans[i];
}

void divide(int l, int r)
{
	if (l < r)
	{
        int mid = (l + r) / 2;
		divide(l, mid);
		divide(mid + 1, r);
		merge(l, r);
	}
}


int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	divide(0, n - 1);

	for (int i = 0; i < n; i++)
		cout << arr[i] << '\n';

	return 0;
}