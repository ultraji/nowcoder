/* 首先输入要输入的整数个数n，然后输入n个整数。输出为n个整数中负数的个数，和所有正整数的
 平均值，结果保留一位小数。 */

#include <iostream>
using namespace std;

int main()
{
    int n, m;
    while(cin >> n)
    {
        int c1 = 0, c2 = 0;
        double aver = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> m;
            if (m > 0) {
                aver += m;
                c1 ++;
            } else if (m < 0) {
                c2 ++;
            }
        }
        printf("%d %.1lf\n", c2, aver/c1);
    }
    return 0;
}