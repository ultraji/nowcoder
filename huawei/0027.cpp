// 0027.查找兄弟单词

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    while(cin >> n)
    {
        getchar();
        vector<string> v, r;
        string s, t1, t2;
        for(int i = 0; i < n; i++)
        {
            cin >> s;
            v.push_back(s);
        }
        cin >> s;
        cin >> m;
        t1 = s;
        sort(t1.begin(), t1.end());
        for(int i = 0; i < n; i++)
        {
            t2 = v[i];
            if (t2 == s) continue;
            if (t2.size() == t1.size()) {
                sort(t2.begin(), t2.end());
                if (t2 == t1) {
                    r.push_back(v[i]);
                }
            }
        }
        sort(r.begin(), r.end());
        cout << r.size() << endl;
        if(r.size() >= m) {
            cout << r[m-1] << endl;
        }
    }
    return 0;
}