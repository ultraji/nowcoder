// 0037.统计每个月兔子的总数

// 斐波那契数列
#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int a = 1, b = 0, c = 0;    // 1个月，2个月，3个月及以上的兔子数
        while(--n)
        {
            c += b;
            b = a;
            a = c;
        }
        cout << a+b+c << endl;
    }
    return 0;
}