// 0023.删除字符串中出现次数最少的字符

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s;
    int np[26] = {0};
    while(getline(cin, s))
    {
        memset(np, 0 ,sizeof(np));
        for(int i = 0; i < s.size(); i++)
        {
            np[s[i]-'a'] ++;
        }
        int mc = 20;
        for(int i = 0; i < 26; i++)
        {
            if(np[i] == 0) continue;
            if(mc > np[i]) mc = np[i];
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(np[s[i]-'a'] != mc) cout << s[i];
        }
        cout << endl;
    }
    return 0;
}