// 0033.整数与IP地址间的转换

#include <iostream>
using namespace std;

int main()
{
    unsigned long n;
    int m[4], i;
    string s;
    while(getline(cin, s))
    {
        s += '.';
        n = 0;
        while(!s.empty())
        {
            i = s.find('.');
            int tmp = stoul(s.substr(0,i));
            n = (n<<8) | tmp;
            s = s.substr(i+1);
        }
        cout << n << endl;
        cin >> n;
        getchar();
        i = 0;
        while(n != 0)
        {
            m[i++] = n%256;
            n/=256;
        }
        for(int i = 3; i > 0; i--)
        {
            cout << m[i] << '.';
        }
        cout << m[0] << endl;
    }
    return 0;
}