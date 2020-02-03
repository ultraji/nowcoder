// 0029.字符串加解密

#include <iostream>
#include <cstring>
using namespace std;

string encode(string s, string r)
{
    r = "";
    char c;
    for(int i = 0; i < s.size(); i++)
    {
        if(isalpha(s[i])) {
            if(isupper(s[i])) {
                c = tolower(s[i]) + 1;
                if(c > 'z') c = 'a';
            } else {
                c = toupper(s[i]) + 1;
                if(c > 'Z') c = 'A';
            }
        }else if(isdigit(s[i])){
            c = s[i] + 1;
            if(c > '9') c = '0';
        }
        r += c;
    }
    return r;
}

string decode(string s, string r)
{
    r = "";
    char c;
    for(int i = 0; i < s.size(); i++)
    {
        if(isalpha(s[i])) {
            if(isupper(s[i])) {
                c = tolower(s[i]) - 1;
                if(c < 'a') c = 'z';
            } else {
                c = toupper(s[i]) - 1;
                if(c < 'A') c = 'Z';
            }
        }else if(isdigit(s[i])){
            c = s[i] - 1;
            if(c < '0') c = '9';
        }
        r += c;
    }
    return r;
}

int main()
{
    string s1, s2, r;
    while(getline(cin, s1))
    {
        getline(cin, s2);
        cout << encode(s1, r) << endl;
        cout << decode(s2, r) << endl;
    }
    return 0;
}