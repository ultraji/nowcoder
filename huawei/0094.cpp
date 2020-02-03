// 0094.记票统计

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n,m;
    while(cin >> n)
    {
        getchar();
        string s1[1000], s2[1000];
        map<string,int> mp;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> s1[i];
            mp[s1[i]] = 0;
        }
        cin >> m;
        getchar();
        for (int i = 0; i < m; i++)
        {
            cin >> s2[i];
            if (mp.find(s2[i]) != mp.end()) {
                mp[s2[i]] ++;
            }else {
                cnt ++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << s1[i] << " : " << mp[s1[i]] << endl;
        }
        cout << "Invalid : " << cnt << endl;

    }
    return 0;
}