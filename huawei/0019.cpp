// 0019.简单错误记录

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int cnt;
    int num;
};

bool cmp(pair<string, node> p1, pair<string, node> p2){
    return p1.second.num > p2.second.num;
}

int main()
{
    string s;
    map<string, node> mp;
    int n = 0, num = 0;
    node no;
    //freopen("in.txt", "r", stdin);
    while (getline(cin, s))
    {
        s = s.substr(s.rfind('\\')+1);
        if(mp.find(s) == mp.end()) {
            no.cnt = 1;
            no.num = num;
            mp[s] = no;
        } else {
            mp[s].cnt ++;
        }
        num ++;
    }
    vector<pair<string, node> > v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), cmp);
    for(int i = v.size()>8?7:(v.size()-1); i >= 0; i--)
    {
        s = v[i].first;
        int idx = s.find(' ');
        if(idx > 16) s = s.substr(idx-16);
        cout << s << ' ' << v[i].second.cnt << endl;
    }
    return 0;
}
