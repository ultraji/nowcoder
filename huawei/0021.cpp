// 0021.简单密码破解

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s;
    string mp[10] = {"0", "1", "abc","def","ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
    while(getline(cin, s))
    {
        for(int i = 0; i < s.size(); i++)
        {
            int c = s[i];
            if (isupper(s[i])) {
                c = s[i]-'A'+1+'a';
                if(c > 'z') c = 'a';
            } else if (islower(s[i])) {
                for(int j = 2; j < 10; j++)
                {
                    if(mp[j].find(s[i]) != mp[j].npos)
                    {
                        c = j + '0';
                    }
                }
            }
            printf("%c", c);
        }
    }
    return 0;
}