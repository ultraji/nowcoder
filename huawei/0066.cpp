// 0066.配置文件恢复

#include <iostream>
using namespace std;

int main()
{
    string s;
    string t1 = "reset";
    string t2[] = {"reset", "board", "board", "reboot", "backplane"};
    string t3[] = {"board", "add", "delet", "backplane", "abort"};
    string an[] = {"board fault", "where to add", "no board at all", "impossible", "install first", "unkown command"};
    while(getline(cin, s))
    {
        int idx = s.find(' ');
        if(idx == s.npos) {
            if(t1.find(s) != t1.npos) cout << "reset what" << endl;
            else cout << "unkown command" << endl;
        } else {
            string s1 = s.substr(0, idx);
            string s2 = s.substr(idx+1);
            int cnt = 0, j = 5;
            for(int i = 0; i < 5; i++)
            {
                string tp1 = t2[i].substr(0, s1.size());
                string tp2 = t3[i].substr(0, s2.size());
                if(tp1 == s1 && tp2 == s2) {
                    cnt ++;
                    j = i;
                }
            }
            if(cnt != 1) j = 5;
            cout << an[j] << endl;
        }
    }
    return 0;
}