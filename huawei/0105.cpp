/* 从输入任意个整型数，统计其中的负数个数并求所有非负数的平均值 */

#include <iostream>
using namespace std;

int main()
{
    double sum = 0;
    int a, c = 0, cnt = 0;
    while(cin >> a)
    {
        if (a < 0) {
            cnt ++;
        }else {
            c ++;
            sum += a;
        }
    }
    printf("%d\n%.1lf", cnt, sum/c);
    return 0;
}