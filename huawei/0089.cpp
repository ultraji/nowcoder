// 0089.24点运算
// 这题不需要考虑括号，测试用例有问题，不再考虑AC

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

string mp = "#A234567891JQK";
string tb = "+-*/";

double op(double a, double b, int opera)
{
    if(opera == 0) return a+b;
    else if(opera == 1) return a-b;
    else if(opera == 2) return a*b;
    else if(opera == 3) return a/b;
    return 0;
}

bool cal24(double a[], int o[])
{
    vector<double> b(a, a+4);
    for(int i = 0; i < 3; i++)
        b[i+1] = op(b[i], b[i+1], o[i]);
    if (fabs(b[3]-24.0)<0.01) return true;
    else return false;
}

bool func(double a[])
{
    bool flag = false;
    int o[4];
    sort(a, a+4);
    do {
        for(int i = 0; i < 4 && !flag; i++) {
            o[0] = i;
            for(int j = 0; j < 4 && !flag; j++) {
                o[1] = j; 
                for(int k = 0; k < 4 && !flag; k++) {
                    o[2] = k;
                    if (cal24(a, o)) {
                        for(int m = 0; m < 3; m++)
                            cout << mp[int(a[m])] << tb[o[m]];
                        cout << mp[int(a[3])]  << endl;
                        flag = true;
                    }
                }
            }
        }
    } while(next_permutation(a, a+4) && !flag);
    return flag;
}

int main()
{
    string s;
    while(getline(cin, s))
    {
        double a[4];
        bool flag = true;
        s += ' ';
        for(int i = 0; i < 4 && flag; i++)
        {
            int f = s.find(' ');
            string t = s.substr(0, f);
            if (t == "joker" || t == "JOKER")
                flag = false;
            a[i] = (double)mp.find(t[0]);
            s = s.substr(f+1);
        }
        if(!flag){
            cout << "ERROR" << endl;
        }else if (!func(a)) {
            cout << "NONE" << endl;
        }
    }
}