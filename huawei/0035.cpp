// 0035.蛇形矩阵

#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int t = 1;
        for(int i = 1; i <= n; i++)
        {
            int s = t;
            for(int j = i; j <= n; j++)
            {
                cout << s << ' ';
                s += j+1;
            }
            cout << endl;
            t += i;
        }
    }
    return 0;
}