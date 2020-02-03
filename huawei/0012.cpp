// 0012.字符串反转

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    char num[10000];
    cin.getline(num,10000);
    reverse(num, num+strlen(num));
    cout << num;
    
    return 0;
}