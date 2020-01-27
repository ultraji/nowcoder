/* 合并表记录 */

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int a, b, n;
    map<int,int> mp;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if(mp.find(a) != mp.end())
        {
            mp[a] += b;
        }else
        {
            mp[a] = b;
        }
    }
    for (auto it = mp.begin(); it != mp.end(); it ++)
    {
        printf("%d %d\n", it->first, it->second);
    }

    return 0;
}