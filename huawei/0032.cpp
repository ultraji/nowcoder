// 0032.字符串运用-密码截取

#include <iostream>
#include <algorithm>
using namespace std;

int LPS(string s)
{
    int maxLen = 0, n = s.size();
    bool p[n][n];
    fill(p[0], p[0]+n*n, false);
    for(int i = 0; i < n; i++) // 遍历每一个字符，并以该字符做中心向两边扩展
    {
        for(int j = 0; i-j >= 0 && i+j < n; j++) // aba 这种单中心的情况
        {
            if(s[i-j] == s[i+j]) {
                p[i-j][i+j] = true;
                if(2*j+1 > maxLen) maxLen = 2*j+1;
            } else {
                p[i-j][i+j] = false;
                break;
            }
        }

        if(s[i] != s[i+1]) continue;

        for(int j = 0; i-j >= 0 && i+1+j < n; j++) // abba 这种双中心的情况
        {
            if(s[i-j] == s[i+1+j]) {
                p[i-j][i+1+j] = true;
                if(2*j+2 > maxLen) maxLen = 2*j+2;
            } else {
                p[i-j][i+1+j] = false;
                break;
            }
        }
    }    

    return maxLen;
}

int main()
{
    string s;
    while(getline(cin, s))
    {
        cout << LPS(s) << endl;
    }
    return 0;
}