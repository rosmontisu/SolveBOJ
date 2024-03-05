#include <iostream>
#include <string>
using namespace std;

int main(void) {
    char keyboard[100] = { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'
        ,'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\''
        ,'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/' };


    char c = ' ';
    while (true) {
        cin >> c;
        if (c == ' ')
            cout << ' ';
        else {
            for (int j = 0; j < 40; j++) {
                if (c == keyboard[j]) {
                    if (j > 0)
                        j -= 1;

                    cout << keyboard[j];
                    break;
                }
            }
        }
    }
}
