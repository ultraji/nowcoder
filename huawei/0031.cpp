// 0031.【中级】单词倒排

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    vector<string> v;
    while(getline(cin, s))
    {
        s += ' ';
        while(!s.empty())
        {
            int i = 0;
            string c = "";
            for(i = 0; i < s.size(); i++)
            {
                if(!isalpha(s[i])) break;
                c += s[i];
            }
            if(!c.empty()) v.push_back(c);
            s = s.substr(i+1);
        }
        for(int i = v.size()-1; i >0; i--)
        {
            cout << v[i] << ' ';
        }
        cout << v[0] << endl;
    }
    return 0;
}