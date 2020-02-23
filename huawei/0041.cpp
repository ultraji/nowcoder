// 0041.称砝码

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    int n, a[10], tmp;
    while (cin >> n)
    {
        vector<int> v;
        set<int> s;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) 
        {
            cin >> tmp;
            for(int j = 0; j < tmp; j++) v.push_back(a[i]);
        }
        s.insert(0);
        for(int i = 0; i < v.size(); i++)
        {
            set<int> t(s);
            for(auto it = t.begin(); it != t.end(); it ++)
            {
                s.insert(*it + v[i]);
            }
        }
        cout << s.size() << endl;
    }
    return 0;
}