/* 汽水瓶 */

#include <iostream>
using namespace std;

int main()
{
    int n, cnt;
    while(cin >> n && n != 0)
    {
        cnt = 0;
        while(n > 1)
        {
            n -= 3;
            cnt += 1;
            n += 1;
        }
        cout << cnt << endl;
    }
    return 0;
}