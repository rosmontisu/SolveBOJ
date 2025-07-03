#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    
    string input;
    getline(cin, input);
    
    int answer = 0;
    size_t pos = 0;
    
    while ((pos = s.find(input, pos)) != string::npos)
    {
        pos += (size_t)input.length();
        answer++;
    }
    
    cout << answer;
}
