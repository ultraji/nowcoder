// 0005.进制转换

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int turn(int c)
{
    int a = toupper(c);
    if(a >= 'A' && a <= 'Z')
    {
        return a - 'A' + 10;
    }
    else {
        return a - '0';
    }
}

int main()
{
    char a[100];
    while(cin.getline(a, 100))
    {
        int sum = 0;
        reverse(a, a + strlen(a));
        for(int i = 0; i < strlen(a); i++)
        {
            if (toupper(a[i]) == 'X') break;
            int t = turn(a[i]);
            for(int j = 0; j < i; j++)
            {
                t *= 16;
            }
            sum += t;
        }
        cout << sum << endl;
    }
    return 0;
}