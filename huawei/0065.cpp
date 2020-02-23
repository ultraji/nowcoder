// 0065.查找两个字符串a,b中的最长公共子串

#include <iostream>
using namespace std;

int lcs(string a, string b)
{
    if(a.size() > b.size()) {
        string tmp = a;
        a = b;
        b = tmp;
    }
    a.insert(0, 1, ' ');
    b.insert(0, 1, ' ');
    int n = a.size(), m = b.size();
    int dp[n][m];
    int maxLen = 0, last;
    for(int i = 0; i < n; i++) dp[i][0] = 0;
    for(int j = 0; j < m; j++) dp[0][j] = 0;
    for(int i = 1; i < n; i++) 
    {
        for(int j = 1; j < m; j++)
        {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(maxLen < dp[i][j]) {
                    maxLen = dp[i][j];
                    last = i;
                }
            } else {
                dp[i][j] = 0;
            } 
        }
    }
    cout << a.substr(last-maxLen+1, maxLen) << endl;
    return maxLen;
}

int main()
{
    string a, b;
    while(cin >> a >> b)
    {
        lcs(a, b);
    }
    return 0;
}