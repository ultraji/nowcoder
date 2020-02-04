// 0036.字符串加密

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s;
    int mp[26] = {0};
    while(getline(cin, s))
    {
        string key = "";
        fill(mp, mp+26, 0);
        for(int i = 0; i < s.size(); i++)
        {
            int c = toupper(s[i])-'A';
            if(mp[c] == 0){
                key += 'A'+c;
                mp[c] = 1;
            }
        }
        for(int i = 0; i < 26; i++)
        {
            if(mp[i] == 0) key += 'A'+i;
        }
        getline(cin, s);
        string res = "";
        for(int i = 0; i < s.size(); i++)
        {
            int c = toupper(s[i])-'A';
            if(islower(s[i])) {
                res += tolower(key[c]);
            }else {
                res += key[c];
            }
        }
        cout << res << endl;
    }
    return 0;
}