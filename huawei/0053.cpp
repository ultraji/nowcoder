// 0053.iNOC产品部-杨辉三角的变形

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int np1[2*n+1], np2[2*n];
        fill(np1, np1+2*n+1, 0);
        fill(np2, np2+2*n, 0);
        np1[1] = np2[1] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
                np2[j] = np1[j] + np1[j-1] + np1[j+1];
            for (int j = i+1; j <= 2*i-1; j++)
                np2[j] = np2[2*i-j];
            memcpy(np1 + 1, np2, n*2*4);
        }
        int res = -1;
        for(int i = 1; i <= n; i++)
        {
            if (np2[i]%2 == 0)
            {
                res = i;
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}