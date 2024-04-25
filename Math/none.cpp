#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	long long n; cin >> n;

	cout << (n * (n - 1) * (n - 2) * (n - 3) * (n - 4)) / 120;
}
