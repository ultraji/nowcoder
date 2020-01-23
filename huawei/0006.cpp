/* 功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）最后一个数后面也要有空格 */

#include <iostream>
#include <cmath>
using namespace std;

int isP(long n)
{
    for(int i = 2; i < sqrt(n); i++)
    {
        if(n/i == 0) return 0;
    }
    return 1;
}

int main()
{
    long n;
    cin >> n;
    for(long i = 2; i <= n;)
    {
        if(n%i == 0) {
            printf("%d ", i);
            n /= i;
        }else {
            for(i++; !isP(i); i++);
        }
    }
    return 0;
}