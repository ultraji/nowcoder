// 0045.名字的漂亮度

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int score(string s)
{
    map<char,int> mp;
    vector<int> v;
    int sum = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if (mp.find(s[i]) == mp.end()) {
            mp[s[i]] = 1;
        }else {
            mp[s[i]] ++;
        }
    }
    for(auto it = mp.begin(); it != mp.end(); it ++)
    {
        v.push_back(it->second);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        sum += (26-i)*v[i];
    }
    return sum;
}

int main()
{
    int n;
    string s;
    while(cin >> n)
    {
        getchar();
        for(int i = 0; i < n; i ++)
        {
            getline(cin, s);
            cout << score(s) << endl;
        }
    }
    return 0;
}