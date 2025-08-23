#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int answer = n;
	for (int i = 0; i < n; i++)
	{
		bool checker[200] = { false };
		string s;
		cin >> s; 
		checker[s[0]] = true;
		for (int i = 1; i < s.length(); i++)
		{
			if (!checker[s[i]])
				checker[s[i]] = true;
			else if (s[i - 1] != s[i])
			{
				answer--;
				break;
			}
		}
	}

	cout << answer;
}