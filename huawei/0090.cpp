/* 合法IP */

#include <iostream>
using namespace std;

int main()
{
    int a,b,c,d;
    while(scanf("%d.%d.%d.%d", &a,&b,&c,&d) != EOF)
    {
        if (a > 255 || b > 255 || c > 255 || d > 255
           || a < 0 || b < 0 || c < 0 || d < 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}