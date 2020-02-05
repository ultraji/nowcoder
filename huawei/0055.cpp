// 0055.（练习用）挑7

#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int mp[30001];
    mp[0] = 0;
    for(int i = 1; i <= 30000; i++)
    {
        string s = to_string(i);
        if(i%7==0 || s.find('7') != s.npos) mp[i] = mp[i-1]+1;
        else mp[i] = mp[i-1];
    }
    while(cin >> n)
    {
        cout << mp[n] << endl;
    }
    return 0;
}