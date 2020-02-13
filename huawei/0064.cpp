// 0064.MP3光标位置

#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;
    while(cin >> n >> s)
    {
        int idx = 1, jdx = 1;
        int maxj = min(n, 4);
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'U') {
                if(idx == 1 && jdx == 1) {
                    idx = n;
                    jdx = maxj;
                } else {
                    idx --;
                    if(jdx != 1) jdx --;
                }
            } else {
                if(idx == n && jdx == maxj) {
                    idx = 1;
                    jdx = 1;
                } else {
                    idx ++;
                    if(jdx != maxj) jdx ++;
                }
            }
        }
        int now = idx;
        for( ; jdx != 1; jdx --) idx --;
        for(int i = 0; i < maxj; i++) cout << idx+i << ' ';
        cout << endl << now << endl;
    }
    return 0;
}