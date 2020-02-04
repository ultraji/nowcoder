// 0040.输入一行字符，分别统计出包含英文字母、空格、数字和其它字符的个数

#include <iostream>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        int a=0, b=a, c=0, d=0;
        for(int i = 0; i < s.size(); i++)
        {
            if(isalpha(s[i])){
                a ++;
            } else if(s[i] == ' ') {
                b ++;
            } else if(isdigit(s[i])) {
                c ++;
            } else {
                d ++;
            }
        }
        printf("%d\n%d\n%d\n%d\n",a,b,c,d);
    }
    return 0;
}