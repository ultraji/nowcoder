/* 写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。*/

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int cnt = 0;
    char s[5001], a;

    cin.getline(s, 5001);
    a = getchar();
    a = toupper(a);
    for(int i = 0; i < strlen(s); i++)
    {
        if(toupper(s[i]) == a){
            cnt ++;
        }
    }
    cout << cnt;

    return 0;
}