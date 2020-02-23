// 0052.计算字符串的距离
// keywords: levenshtein距离

#include <iostream>
#include <cmath>
using namespace std;

int findMin(int a, int b, int c)
{
    a = min(a, b);
    b = min(b, c);
    return min(a, b);
}

int levenshtein(string a, string b)
{
    a.insert(0, 1,' ');
    b.insert(0, 1, ' ');
    int n = a.size(), m = b.size();
    int cost, lev[n][m];
    for(int i = 0; i < n; i++) lev[i][0] = i;
    for(int j = 0; j < m; j++) lev[0][j] = j;
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(a[i] == b[j]) cost = 0;
            else cost = 1;
            lev[i][j] = findMin(lev[i][j-1]+1, 
                lev[i-1][j]+1, lev[i-1][j-1]+cost);
        }
    }
    return lev[n-1][m-1];
}

int main()
{
    string a, b;
    while(cin >> a >> b)
    {
        cout << levenshtein(a, b) << endl;
    }
    return 0;
}