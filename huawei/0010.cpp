/* 字符个数统计 */

#include <iostream>
#include <cstring>
using namespace std;

int mp[128];

int main()
{
    int c, cnt;
    c = getchar();
    while(c != '\n')
    {
        if(c >= 0 && c<=127)
        {
            if(mp[c] == 0)
            {
                mp[c] = 1;
                cnt ++;
            }
        }
        c = getchar();
    }
    cout << cnt;
    
    return 0;
}