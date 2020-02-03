// 0074.参数解析

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        vector<string> v;
        s += ' ';
        while(!s.empty())
        {
            if(s[0] == '"') {
                int f = s.find('"', 1);
                v.push_back(s.substr(1, f-1));
                s = s.substr(f+2);
            }else{
                int f = s.find(' ');
                v.push_back(s.substr(0, f));
                s = s.substr(f+1);
            }
        }
        cout << v.size() << endl;
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i] << endl;
        }
    }
    return 0;
}