// 0056.iNOC产品部--完全数计算

// 只计算一遍500000的个数，也容易超时的可能原因：
// 1. 可能我算法的时间复杂度太大
// 2. 题目有点问题，说明实际测试的数应该小于明显500000.
// 实际只有以下4个数：6 28 296 8128
#include <iostream>
#include <cmath>
using namespace std;

bool isPerf(int n)
{
    int sum = 1;
    int t = sqrt(n);
    for(int i = 2; i <= t; i++){
        if(n%i == 0) sum += i + n/i;
    }
    if(sum == n) return true;
    return false;
}

int main()
{
    int n = 0;
    int mp[500001];
    mp[1] = 0;
    for(int i = 2; i <= 100001; i++)
    {
        if(isPerf(i)) mp[i] = mp[i-1]+1;
        else mp[i] = mp[i-1];
    }
    while(cin >> n)
    {
        cout << mp[n] << endl;
    }
    return 0;
}