/* 在字符串中找出连续最长的数字串 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        vector<int> v;
        int cnt = 0, mx = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i])){
                cnt ++;
                if(cnt > mx){
                    mx = cnt;
                    v.clear();
                }
                if (cnt == mx) {
                    v.push_back(i-cnt+1);
                }
            } else {
                cnt = 0;
            }
        }
        for(int i = 0; i < v.size(); i++)
        {
            cout << s.substr(v[i], mx);
        }
        cout << ',' << mx << endl;
    }
    return 0;
}