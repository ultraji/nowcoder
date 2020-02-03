// 0006.质数因子

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