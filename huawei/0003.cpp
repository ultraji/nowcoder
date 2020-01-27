/* 明明的随机数 */

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int mp[1001], n, m;
    while(cin >> n)
    {
        memset(mp, 0, sizeof(mp));
        for(int i = 0; i < n; i++)
        {
            cin >> m;
            mp[m] = 1;
        }
        for(int i = 1; i < 1001; i ++)
        {
            if(mp[i]) cout << i << endl;
        }
    }
    
    return 0;
}