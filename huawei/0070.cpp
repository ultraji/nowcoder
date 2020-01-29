/* 矩阵乘法计算量估算 */

#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

int main()
{
    int n, a, b;
    string s;
    while(cin >> n)
    {
        int cnt = 0;
        vector<pair<int, int> > v;
        stack<pair<int, int> > st;
        for(int i = 0; i < n; i++)
        {
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }
        getchar();
        getline(cin, s);
        for(int i = 0, j = 0; i < s.size(); i++)
        {
            if (s[i] != '(' && s[i] != ')') {
                st.push(v[j++]);
            } else if(s[i] == ')') {
                if(st.size() == 1) break; //测试用例中出现了括号不匹配的例子。
                pair<int, int> p1 = st.top();
                st.pop();
                pair<int, int> p2 = st.top();
                st.pop();
                st.push(make_pair(p2.first, p1.second));
                cnt += p2.first * p1.first * p1.second;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}