/* 超长正整数相加 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string a, string b)
{
    string r = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a.size() < b.size())
    {
        a.append(b.size()-a.size(), '0');
    } else if(a.size() > b.size())
    {
        b.append(a.size()-b.size(), '0');
    }
    int c = 0;
    for(int i = 0; i < a.size(); i++)
    {
        int t = a[i] + b[i] - '0'*2 + c;
        r.append(1, t % 10+'0');
        c = t / 10;
    }
    if(c) r.append(1, c+'0');
    reverse(r.begin(), r.end());
    return r;
}

int main()
{
    string s1, s2;
    while(getline(cin, s1))
    {
        getline(cin, s2);
        cout << add(s1, s2) << endl;
    }
}