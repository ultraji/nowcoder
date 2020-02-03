// 0002.计算字符个数

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