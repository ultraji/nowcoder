/* 计算字符串最后一个单词的长度，单词以空格隔开。*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int i = 0, cnt = 0;
    char s[5001];

    cin.getline(s, 5001);
    for(i = strlen(s)-1; i >= 0 && s[i]==' '; i--);
    for(; i >= 0; i--)
    {
        if(s[i] == ' ') break;
        cnt ++;
        
    }
    cout << cnt;

    return 0;
}
