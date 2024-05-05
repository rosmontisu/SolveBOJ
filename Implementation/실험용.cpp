#include <iostream>
#include <string>
using namespace std;

int flr[10003];

int main(void)
{
	int f, n;
	cin >> f >> n; // 아파트 층수, 참가자의 수
	
	// flr[n] 배열에는 n번째 층수의 사람의 번호가 저장된다.
	// 1사람은 2개의 손을 가지므로, 참가자의 수 m*2 만큼의 층수가 저장된다.
	
	for (int i = 1; i <= n; i++)
	{
	    int n1, n2; // 손층수 1, 손층수 2
	    cin >> n1 >> n2;
	    flr[n1] = i;
	    flr[n2] = i;
	}
    
    int targetFlr = f % (2 * n);
    if (targetFlr == 0) targetFlr = 2 * n; // 0이면 가장 마지막 손 위치
    cout << flr[targetFlr];
}