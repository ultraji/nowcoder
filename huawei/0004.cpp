/*
•连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组；
•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
*/

#include <iostream>
#include <cstring>
using namespace std;

void prints(char *s, int len)
{
    if(len <= 8)
    {
        int i = 0;
        for (; i < len; i++) cout << s[i];
        for (; i < 8; i++) cout << '0';
        cout << endl;
    }else {
        prints(s, 8);
        prints(s+8, len-8);
    }
    return ;
}

int main(){
    char a[101];
    for(int i = 0; i < 2; i++)
    {
        cin.getline(a, 101);
        prints(a, strlen(a));
    }
    return 0;
}