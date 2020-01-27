/* 数据分类处理 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, tmp;
    while(cin >> n)
    {
        int v[10000];
        map<int, vector<pair<int, int> > > mp;
        set<int> st;
        int cnt = 0;
        for (int i = 0; i < n; i++) cin >> v[i];
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> tmp;
            st.insert(tmp);
        }
        for(auto it = st.begin(); it != st.end(); it ++)
        {
            for(int i = 0; i < n; i++)
            {
                string s1 = to_string(v[i]);
                string s2 = to_string(*it);
                if(s1.find(s2) != s1.npos) {
                    mp[*it].push_back(make_pair(i, v[i]));
                    cnt += 2;
                }
            }
        }
        cout << cnt + mp.size() * 2;
        for(auto it = mp.begin(); it != mp.end(); it ++)
        {
            cout << ' ' << it->first << ' ' << (it->second).size();
            for (auto jt = (it->second).begin(); jt != (it->second).end(); jt ++)
            {
                cout << ' ' << jt->first << ' ' << jt->second;
            }
        }
        cout << endl;
    }
    return 0;
}