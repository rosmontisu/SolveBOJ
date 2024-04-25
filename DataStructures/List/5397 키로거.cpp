#include <iostream>
#include <list>
using namespace std;

int main()
{
    int t; string str;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> str;
        list<char> L;
        list<char>::iterator cursor = L.begin();

        for (auto c : str)
        {
            if (c == '<') {
                if (cursor != L.begin())cursor--;
            }
            else if (c == '>') {
                if (cursor != L.end()) cursor++;
            }
            else if (c == '-') {
                if (cursor != L.begin()) cursor = L.erase(--cursor);
            }
            else {
                L.insert(cursor, c);
                // insert 하는 순간 커서는 ++ 된다.
            }
        }
        for (auto c : L)
            cout << c;

        cout << '\n';
    }
}
