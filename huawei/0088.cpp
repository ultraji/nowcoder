// 0088.扑克牌大小

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string tb = "345678910JQKA2jokerJOKER";
    string s;
    while(getline(cin, s))
    {
        int idx = s.find('-');
        string t1 = s.substr(0,idx);
        string t2 = s.substr(idx+1);
        int c1 = count(t1.begin(), t1.end(), ' ');
        int c2 = count(t2.begin(), t2.end(), ' ');
        if(c1 != c2) {
            if(t1 == "joker JOKER" || t2 == "joker JOKER") {
                cout << "joker JOKER" << endl;
            }else if(c1 == 3 ){
                cout << t1 << endl;
            }else if(c2 == 3){
                cout << t2 << endl;
            }else {
                cout << "ERROR" << endl;
            }
        } else {
            string s1 = t1 + ' ', s2 = t2 + ' ';
            s1 = s1.substr(0, s1.find(' '));
            s2 = s2.substr(0, s2.find(' '));
            int i1 = tb.find(s1);
            int i2 = tb.find(s2);
            if(i1 > i2) {
                cout << t1 << endl;
            } else {
                cout << t2 << endl;
            }
        }
    }
    return 0;
}