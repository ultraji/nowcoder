// 0091.201301 JAVA 题目2-3级

#include <iostream>
using namespace std;

int f(int n, int m)
{
    if(n == 0&& m == 0) return 0;
    else if(n == 0) return 1;
    else if(m == 0) return 1;
    else return f(n-1, m) + f(n, m-1);
}

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        cout << f(n, m) << endl;
    }
    return 0;
}