#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<char, int> p1, pair<char, int> p2)
{
    if(toupper(p1.first) == toupper(p2.first)) return p1.second < p2.second;
    return toupper(p1.first) < toupper(p2.first);
}

int main()
{
    string s;
    while(getline(cin, s))
    {
        vector<pair<char, int> > v;
        for(int i = 0; i < s.size(); i++)
        {
            if(!isalpha(s[i])) continue;
            v.push_back(make_pair(s[i], i));
        }
        sort(v.begin(), v.end(), cmp);
        for(int i = 0, j = 0; i < s.size(); i++)
        {
            if (!isalpha(s[i])) {
                cout << s[i];
            }else {
                cout << v[j++].first;
            }
        }
        cout << endl;
    }
    return 0;
}