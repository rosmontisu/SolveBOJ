#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char keyboard[100] = { 
        '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
        'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'
        ,'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\''
        ,'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/' 
    };


    string s;
    while (getline(cin, s)) {

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ')
                cout << s[i];

            else {
                for (int j = 0; j < 47; j++) {
                    if (s[i] == keyboard[j]) {
                        cout << keyboard[j - 1];
                        break;
                    }
                }
            }
        }
        cout << '\n';
    }
    
    return 0;
}
