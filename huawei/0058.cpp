// 0058.输入n个整数，输出其中最小的k个

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a+n);
        for(int i = 0; i < m; i++)
            cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}
