#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	int n; cin >> n;
	// n = 3x2^k (3, 6, 12, 24, 48 ... )

	// 012 345
	// 135 7911

	for (int i = 0; i <= n; i+=3) {
		for (int j = 0; j < n - i + 2; j++)
			cout << ' ';
		cout << "*\n";
		for (int j = 0; j < n - i + 1; j++)
			cout << ' ';
		cout << "* *\n";
		for (int j = 0; j < n - i; j++)
			cout << ' ';
		cout << "*****\n";
	}
}
