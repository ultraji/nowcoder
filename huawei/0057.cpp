// 0057.无线OSS－高精度整数加法
// keywords：模拟加法、模拟减法

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string a, string b)
{
    string r = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.size() < b.size()) a.append(b.size()-a.size(), '0');
    else if (a.size() > b.size()) b.append(a.size()-b.size(), '0');
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

string sub(string a, string b)
{
    string r = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(a.size() < b.size()) a.append(b.size()-a.size(), '0');
    else if(a.size() > b.size()) b.append(a.size()-b.size(), '0');
    for(int i = 0; i < b.size(); i++)
    {
        int t = a[i] - b[i];
        if (t < 0) {
            t += 10;
            int j = i;
            for(; a[j] == '0'; j ++) {
                a[i] = '9';
            }
            a[j] -= 1;
        }
        r.append(1, t + '0');
    }
    reverse(r.begin(), r.end());
    while(r[0] == '0') r.erase(0, 1);
    return r;
}

int main()
{
    string s1, s2;
    while(cin >> s1 >> s2)
    {
        string r;
        if(s1[0] != '-' && s2[0] != '-') {
            r = add(s1, s2);
        } else if(s1[0] == '-' && s2[0] == '-') {
            r = add(s1.substr(1), s2.substr(1));
            r.insert(0, 1, '-');
        } else {
            string t1, t2;
            if(s1[0] == '-') {
                t1 = s1.substr(1);
                t2 = s2;
            } else {
                t1 = s2.substr(1); 
                t2 = s1;  
            }
            if (t1 > t2 || t1.size() > t2.size()) {
                r = sub(t1, t2);
                r.insert(0, 1, '-');
            }else {
                r = sub(t2, t1);
            }
        } 
        cout << r << endl;
    }
    return 0;
}