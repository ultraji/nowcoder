// 0106.字符逆序

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