#include <iostream>
using namespace std;
int main()
{
    while(true)
    {
        int x; cin >> x;
        if (x == -1) break;

        int sum = 0;
        int answer[100001] = {};
        int count = 0;

        for (int i = 1; i < x; i++)
        {
            if((x%i) == 0) 
            {
                sum += i;
                answer[count] = i;
                count++;
            }    
        }    
        if (sum == x)
        {
            cout << x << " = ";
            for (int i = 0; i < count; i++)
            {
                cout << answer[i];
                if (i < count - 1)
                    cout << " + ";
            }

            cout << '\n';
        }
        else cout << x << " is NOT perfect.\n";
    }
}