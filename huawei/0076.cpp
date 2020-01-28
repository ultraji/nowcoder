/* 尼科彻斯定理 */

#include <iostream>
using namespace std;

int main()
{
    int n, m;
    while(cin >> n)
    {
        m = n*n - n + 1;
        for(int i = 0; i < n-1; i++)
        {
            cout << m+2*i << '+';
        }
        cout << m+2*(n-1) << endl;
    }
    return 0;
}