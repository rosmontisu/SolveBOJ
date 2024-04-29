#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
/*
연산의 수 M 은 최대 3백만번이다.
메모리 제한은 4MB로 작게 잡혀있다.
또한, 중복되는 숫자가 없는 집합을 구현하는 문제이므로, 비트마스크를 이용하자
*/

void add(int x); 
void remove(int x);
bool check(int x); // x가 있는가 ? true : false
void toggle(int x); // x가 있는가 ? 제거 : 추가
void all();	// { 11111 11111 11111 11111}
void empty(); // { 00000 00000 00000 00000 }

int S; // 집합 S{}

// switch에서 string을 쓰기위한 해쉬화
constexpr unsigned int HashCode(const char* str)
{
	return str[0] ? static_cast<unsigned int>(str[0]) + 0xEDB8832FULL * HashCode(str + 1) : 8603;
}

void add(int x)
{
	S |= (1 << x);
}
void remove(int x)
{
	S &= ~(1 << x);
}
bool check(int x)
{
	if (S & (1 << x))
		return 1;
	else
		return 0;
}
void toggle(int x)
{
	if (check(x))
		remove(x);
	else
		add(x);
}
void all()
{
	S = -1;
}
void empty()
{
	S = 0;
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m; cin >> m;
	while (m--)
	{
		string str; int n;
		cin >> str;
		const char* cstr = str.c_str();
		switch (HashCode(cstr))
		{
		case HashCode("add"):
			cin >> n;
			add(n);
			break;
		case HashCode("remove"):
			cin >> n;
			remove(n);
			break;
		case HashCode("check"):
			cin >> n;
			cout << check(n) << '\n';
			break;
		case HashCode("toggle"):
			cin >> n;
			toggle(n);
			break;
		case HashCode("all"):
			all();
			break;
		case HashCode("empty"):
			empty();
			break;
		}
	}
}