// 0030.字符串合并处理

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string a, b, s;
    string np = "0123456789ABCDEF";
    char c;
    char mp[16] = {'0','8','4','C','2','A','6','E','1','9','5','D','3','B','7','F'};
    while(cin >> a >> b)
    {
        s = a+b;
        a = "";
        b = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(i%2 == 0) a += s[i];
            else b += s[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        s = "";
        for(int i = 0; i < a.size(); i++)
        {
            s += a[i];
            if(i < b.size()) s += b[i];
        }
        a = "";
        for(int i = 0; i < s.size(); i++)
        {
            c = s[i];
            if ((c <= 'f' && c >= 'a') || (c <= 'F' && c >= 'A') 
                || (c <= '9' && c >= '0')) {
                c = mp[np.find(toupper(c))];
            }
            a += c;
        }
        cout << a << endl;
    }
    return 0;
}