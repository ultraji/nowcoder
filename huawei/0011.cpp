/*
 输入一个整数，将这个整数以字符串的形式逆序输出
 程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001 
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    char num[100];
    cin.getline(num,100);
    reverse(num, num+strlen(num));
    cout << num;
    
    return 0;
}