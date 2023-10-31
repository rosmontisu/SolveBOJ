#include <iostream>
using namespace std;

int freq[26];
int main(void)
{
    string str;
    cin >> str;
    
    for(auto c : str)
        freq[c-'a'] += 1;
    for(int i = 0; i < 26; i++)
        cout << freq[i] << ' ';
        
    return 0;
}
