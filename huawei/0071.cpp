/* 字符串通配符 */

#include <iostream>
using namespace std;

bool match(string a, string b)
{
    // 可以做一下剪枝
    for(int i = 0, j = 0; i < a.size(); i++, j++)
    {
        if (a[i] == '*') {
            bool f = false;
            string s = a.substr(i+1);
            for (int k = j; k < b.size(); k++)
            {
                f = f || match(s, b.substr(k));
            }
            return f;
        }
        else if (a[i] == '?') {
            continue;
        }else if (a[i] != b[j]) {
            return false;
        }
    }
    return true;
}

int main()
{
    string a, b;
    while(getline(cin, a))
    {
        getline(cin, b);
        if (match(a, b)) {
            cout << "true" << endl;
        }else {
            cout << "false" << endl;
        }
            
    }
    return 0;
}