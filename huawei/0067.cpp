// 0067.24点游戏算法

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

double op(double a, double b, int opera)
{
    if(opera == 0) return a+b;
    else if(opera == 1) return a-b;
    else if(opera == 2) return a*b;
    else if(opera == 3) return a/b;
    return 0;
}

bool cal24(vector<double> a, vector<int> o)
{
    // 考虑括号导致优先级变化
    bool flag = false;
    if(o.empty()) {
        if( fabs(a[0]-24.0) < 0.01) flag = true;
    } else {
        for (int i = 0; i < o.size() && !flag; i++)
        {
            a[i] = op(a[i], a[i+1], o[i]);
            a.erase(a.begin()+i+1);
            o.erase(o.begin()+i);
            flag |= cal24(a, o);
        }
    }
    return flag;
}

int main()
{
    double a[4];
    int o[3];
    while(cin >> a[0] >> a[1] >> a[2] >> a[3])
    {
        bool flag = false;
        sort(a, a+4);
        do {
            for(int i = 0; i < 4 && !flag; i++) {
                o[0] = i;
                for(int j = 0; j < 4 && !flag; j++) {
                    o[1] = j; 
                    for(int k = 0; k < 4 && !flag; k++) {
                        o[2] = k;
                        vector<double> va(a, a+4);
                        vector<int> vo(o, o+3);
                        if(cal24(va, vo)) flag = true;
                    }
                }
            }
        } while (next_permutation(a, a+4) && !flag);
        if( flag ) cout << "true" << endl;
        else cout << "false" << endl;
    }
    return 0;
}
