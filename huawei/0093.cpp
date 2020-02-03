// 0093.201301 JAVA题目0-1级

#include <iostream>
using namespace std;

int f(int sum1, int sum2, int v[], int idx, int n)
{
    if (idx < n) {
        return f(sum1+v[idx], sum2, v, idx+1, n) + f(sum1, sum2+v[idx], v, idx+1, n);
    }else{
        if(sum1 == sum2) return 1;
        else return 0;
    }
}

int main()
{
    int n, m;
    while(cin >> n)
    {
        int v[1000];
        int sum1 = 0, sum2 = 0, j = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> m;
            if(m % 5 == 0) sum1 += m;
            else if (m % 3 == 0) sum2 += m;
            else v[j++] = m;
        }
        int r = f(sum1, sum2, v, 0, j);
        if(r > 0) {
            cout << "true" << endl;
        }else {
            cout << "false" << endl;
        }
    }
    return 0;
}