// 0072.百钱买百鸡问题

#include <iostream>
using namespace std;

void f()
{
    int x, y, z;
    for (x = 0; x <= 300/15; x++)
    {
        y = (200 - 14 * x) / 8;
        z = 100 - x - (200 - 14 * x) / 8;
        if ((200 - 14 * x) % 8 == 0 && y >= 0)
        {
            printf("%d %d %d\n", x, y, z);
        }
    }
    return ;
}

int main()
{
    int n;
    while(cin >> n)
    {
        f();
    }
    return 0;
}