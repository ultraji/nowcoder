// 0047.线性插值
// PS: 这题指的重复数据，连续两个编号相同的数据使用第一组。
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int m, n, a, b, c, d;
    while (cin >> m >> n)
    {
        map<int, int> mp;
        cin >> a >> b;
        mp[a] = b;
        cout << a << ' ' << b << endl;
        for(int i = 0; i < m-1; i++)
        {
            cin >> c >> d;
            if ( c == a ) continue;
            mp[c] = d;
            if (c - a > 1) {
                for(int i = 1; i < c-a; i++)
                {
                    cout << a+i << ' ' << b+(d-b)/(c-a)*i << endl;
                }
            }
            cout << c << ' ' << d << endl;
            a = c;
            b = d;
        }
    }
    
    return 0;
}