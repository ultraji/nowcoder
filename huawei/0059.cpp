// 0059.找出字符串中第一个只出现一次的字符

#include <iostream>
using namespace std;

int main()
{
    string s;
    int np[128];
    while(getline(cin, s))
    {
        fill(np, np+128, 0);
        for(int i = 0; i < s.size(); i++) np[s[i]] ++;
        string r = "";
        for(int i = 0; i < 128; i++) if(np[i] == 1) r+= (char)i;
        if (r.empty()) {
            cout << -1 << endl;
            continue;
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(r.find(s[i]) != r.npos){
                cout << s[i] << endl;
                break;
            }
        }
    }
    return 0;
}