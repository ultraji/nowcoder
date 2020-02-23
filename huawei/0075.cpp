// 0075.公共字串计算

#include <iostream>
using namespace std;

int lcs(string a, string b)
{
    int maxLen = 0;
    a.insert(0, 1, ' ');
    b.insert(0, 1, ' ');
    int n = a.size(), m = b.size();
    int dp[n][m];
    for(int i = 0; i < n; i++) dp[i][0] = 0;
    for(int j = 0; j < m; j++) dp[0][j] = 0;
    for(int i = 1; i < n; i++) 
    {
        for(int j = 1; j < m; j++)
        {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                maxLen = max(maxLen, dp[i][j]);
            } else {
                dp[i][j] = 0;
            } 
        }
    }
    return maxLen;
}

int main()
{
    string a, b;
    while(cin >> a >> b)
    {
        cout << lcs(a, b) << endl;
    }
    return 0;
}