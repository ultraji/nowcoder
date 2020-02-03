// 0097.记负均正

#include <iostream>
using namespace std;

int main()
{
    int n, m;
    while(cin >> n)
    {
        int c1 = 0, c2 = 0;
        double aver = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> m;
            if (m > 0) {
                aver += m;
                c1 ++;
            } else if (m < 0) {
                c2 ++;
            }
        }
        printf("%d %.1lf\n", c2, aver/c1);
    }
    return 0;
}