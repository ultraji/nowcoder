// 0011.数字颠倒

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