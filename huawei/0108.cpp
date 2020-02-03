// 0108.求最小公倍数

//由于两个数的乘积等于这两个数的最大公约数与最小公倍数的积

#include <iostream>
using namespace std;

int gcd(int x, int y)
{  
    while (x * y)
    {  
        if (x > y) {  
            x %= y;  
        } else if (x < y) {  
            y %= x;  
        }  
    }  
    return x > y ? x : y;  
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a * b / gcd(a, b);
    return 0;
}