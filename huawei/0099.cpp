/* 自守数是指一个数的平方的尾数等于该数自身的自然数。例如：25^2 = 625，76^2 = 5776，9376^2 = 87909376。
 请求出n以内的自守数的个数 */

#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            int j = 10;
            for(; i%j != i; j *= 10);
            if (i*i % j== i) cnt ++;
        }
        cout << cnt << endl;
    }
    return 0;
}