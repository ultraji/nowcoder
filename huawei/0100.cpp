/*
功能:等差数列 2，5，8，11，14。。。。
输入:正整数N >0
输出:求等差数列前N项和
返回:转换成功返回 0 ,非法输入与异常返回-1
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        cout << n*(2+3*n-1)/2 << endl;
    }
    return 0;
}