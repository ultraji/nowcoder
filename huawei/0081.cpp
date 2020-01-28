/* 字符串匹配 */

#include <iostream>
#include <cstring>
using namespace std;

char mp[128];

int main()
{
    char s[1000],l[1000];
    while(cin.getline(s,1000))
    {
        cin.getline(l,1000);
        memset(mp, 0, 128);
        for(int i = 0; i < strlen(s); i++)
        {
            mp[s[i]] = 1;
        }
        for(int i = 0; i < strlen(l); i++)
        {
            mp[l[i]] = 0;
        }
        string flag = "true";
        for(int i = 0; i < 128; i++)
        {
            if (mp[i]) {
                flag = "false";
                break;
            }
        }
        cout << flag << endl;
    }
    return 0;
}