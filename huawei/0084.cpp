/* 统计大写字母个数 */

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        int cnt = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(isupper(s[i])) cnt ++;
        }
        cout << cnt << endl;
    }
    return 0;
}