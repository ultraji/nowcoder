// 0004.字符串分隔

#include <iostream>
#include <cstring>
using namespace std;

void prints(char *s, int len)
{
    if(len <= 8) {
        int i = 0;
        for (; i < len; i++) cout << s[i];
        for (; i < 8; i++) cout << '0';
        cout << endl;
    } else {
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