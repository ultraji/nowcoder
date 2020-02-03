// 0102.字符统计

#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<char, int> p1, pair<char, int> p2)
{
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
}

int main()
{
    string s;
    while(getline(cin, s))
    {
        map<char, int> mp;
        vector<pair<char, int> > v;
        for(int i = 0; i < s.size(); i++)
        {
            if (isspace(s[i]) || isalnum(s[i]))
            {
                mp[s[i]] ++;
            }
        }
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            v.push_back(make_pair(it->first, it->second));
        }
        sort(v.begin(), v.end(), cmp);
        for(auto it = v.begin(); it != v.end(); it++)
        {
            cout << it->first;
        }
        cout << endl;
    }
    return 0;
}