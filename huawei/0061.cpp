// 0061.放苹果

#include <iostream>
using namespace std;

int f(int m, int n)
{
    if(m < 0) return 0;
    if(m == 1 || n == 1) return 1;
    return f(m, n-1) + f(m-n, n);
}

int main()
{
    int m, n;
    while(cin >> m >> n)
    {
        cout << f(m, n) << endl;
    }
    return 0;
}