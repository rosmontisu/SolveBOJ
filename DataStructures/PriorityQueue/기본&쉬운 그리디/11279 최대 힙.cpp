#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    priority_queue<int> heap;

    int n; cin >> n;
    while(n--)
    {
        int input;
        cin >> input;
        if (input == 0)
        {
            if (heap.empty()) cout << 0 << '\n';
            else
            {
                cout << heap.top() << '\n';
                heap.pop();
            }
            
        }   
        else
            heap.push(input);
    }
} 
