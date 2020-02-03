// 0024.合唱队

#include <iostream>
using namespace std;

int main()
{
    int n;
    int m[10000], dp1[10000], dp2[10000];
    while(cin >> n)
    {
        for(int i = 0; i < n; i++)
        {
            cin >> m[i];
            dp1[i] = 1;
            for(int j = 0; j < i; j++)
            {
                if(m[i] > m[j]) dp1[i] = max(dp1[i], dp1[j]+1);
            }
        }
        for(int i = n-1; i >= 0; i--)
        {
            dp2[i] = 1;
            for(int j = n-1; j >= i; j--)
            {
                if(m[i] > m[j]) dp2[i] = max(dp2[i], dp2[j]+1);
            }
        }
        int mn = 0;
        for(int i = 0; i < n; i++)
        {
            if(dp1[i] + dp2[i] - 1 > mn) mn = dp1[i] + dp2[i] - 1;
        }
        cout << n-mn << endl;
    }
    return 0;
}