/* 密码验证合格程序 */

#include <iostream>
using namespace std;

int main()
{
    string s;
    while( getline(cin, s) )
    {
        int A = 0, a = 0, num = 0, ctl = 0;
        if(s.size() <= 8) {
            cout << "NG" <<endl;
            continue;
        }
        for(int i = 0; i < s.size(); i++)
        {
            if(isupper(s[i])){
                A = 1;
            } else if(islower(s[i])){
                a = 1;
            } else if(isdigit(s[i])){
                num = 1;
            } else {
                ctl = 1;
            }
        }
        if (A+a+num+ctl < 3) {
            cout << "NG" <<endl;
            continue;
        }
        int findFlag = false;
        for(int i = 0; i < s.size()-6; i ++)
        {
            string s1 = s.substr(i,3);
            string s2 = s.substr(i+3);
            if (s2.find(s1) != s2.npos) {
                findFlag = true;
                break;
            }
        }
        if (findFlag) {
            cout << "NG" <<endl;
            continue;
        }
        cout << "OK" << endl;
    }
    return 0;
}