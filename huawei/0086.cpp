// 0086.求最大连续bit数

#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int mcnt = 0, cnt = 0;
        while(n != 0)
        {
            if(n%2 == 1) {
                cnt ++;
                mcnt = max(mcnt, cnt);
            }else {
                cnt = 0;
            }
            n /= 2;
        }
        cout << mcnt << endl;
    }
    return 0;
}