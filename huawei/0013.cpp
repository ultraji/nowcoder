/* 句子逆序 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string s;
    stack<string> sa;
    while(cin >> s)
    {
        sa.push(s);
    }
    while(!sa.empty())
    {
        s = sa.top();
        sa.pop();
        cout << s << ' ';
    }
    
    return 0;
}