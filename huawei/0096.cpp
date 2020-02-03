// 0096.表示数字

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        s.insert(0, 1, 'a');
        s.append(1, 'a');
        for(int i = 1; i < s.size(); i ++)
        {
            if (!isdigit(s[i-1]) && isdigit(s[i])) {
                cout << '*';
            }else if(isdigit(s[i-1]) && !isdigit(s[i])) {
                cout << '*';
            }
            if(i != s.size()-1) cout << s[i];
        }
        cout << endl;
    }
    return 0;
}