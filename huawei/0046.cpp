// 0046.按字节截取字符串

// 根据题意，在判题系统中，汉字以2个字节存储。
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s;
    int n;
    while(cin >> s >> n)
    {
        if(s[n-1] < 0) s = s.substr(0, n-1);
        else s = s.substr(0, n);
        cout << s << endl;
    }
    return 0;
}