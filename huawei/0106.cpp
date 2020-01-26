/* 将一个字符串str的内容颠倒过来，并输出。
 str的长度不超过100个字符。 如：输入“I am a student”，
 输出“tneduts a ma I”。 */

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    char a[101];
    cin.getline(a, 101);
    reverse(a, a+strlen(a));
    cout << a;
    return 0;
}