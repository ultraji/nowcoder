/* 密码强度等级 */

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s;
    string r[7] =  {"VERY_WEAK", "WEAK", "AVERAGE", "STRONG", 
        "VERY_STRONG", "SECURE", "VERY_SECURE"};
    int ss[7] = {25, 25, 10, 10, 10, 10, 100};
    while(getline(cin, s))
    {
        int score = 0;
        if(s.size() <= 4){
            score += 5;
        }else if(s.size() >= 8) {
            score += 25;
        }else {
            score += 10;
        }
        
        int t1 = 0, t2 = 0, t3 = 0, t4 = 0, c1 = 0, c2 = 0, t;
        for(int i = 0; i < s.size(); i++)
        {
            if(islower(s[i])) {
                t1 = 1;
            } else if (isupper(s[i])) {
                t2 = 1;
            }else if (isdigit(s[i])) {
                t3 = 1;
                c1 ++;
            }else if (ispunct(s[i])) {
                t4 = 1;
                c2 ++;
            }
        }
        if(c1 > 1) c1 = 2;
        if(c2 > 1) {
            c2 = 15;
        } else {
            c2 = 0;
        }
        score += t1*10 + t2*10 + t3*10*c1 + t4*10+c2; 

        t = t1 + t2 + t3 + t4;
        if (t == 4) {
            score += 5;
        } else if(t1+t2==1 && t == 3) {
            score += 3;
        } else if (t1+t2>1 && t3 == 1) {
            score += 2;
        }
        for(int i = 0; i < 7; i++)
        {
            score -= ss[i];
            if(score < 0) {
                cout << r[i] << endl;
                break;
            }
        }
    }
    return 0;
}