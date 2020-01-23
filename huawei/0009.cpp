#include <iostream>
using namespace std;

int mp[10];

int main()
{
    int num;
    cin >> num;
    if(num == 0) cout << 0;
    while(num != 0)
    {
        int t = num%10;
        if(mp[t] == 0)
        {
            mp[t] = 1;
            cout << t;
        }
        num /= 10;
    }
    return 0;
}