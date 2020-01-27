/* 查找输入整数二进制中1的个数 */

#include <iostream>
using namespace std;

int cnt(int num)
{
    int cnt = 0;
    while(num != 0)
    {
        if( num % 2 ) cnt ++;
        num /= 2;
    }
    return cnt;
}

int main()
{
    int num;
    while(cin >> num)
    {
        cout << cnt(num) << endl;
    }
    return 0;
}