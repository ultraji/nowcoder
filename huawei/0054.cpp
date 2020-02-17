// 0054.表达式求值

#include <iostream>
#include <stack>
using namespace std;

string mp = "+-*/)";

bool cmp(char c1, char c2)
{
    if (c1 =='(') {
        return false;
    } else if((c1=='+' || c1=='-') && (c2=='*' || c2=='/')){
        return false;
    }
    return true;
}

void doCal(stack<double> &st, stack<char> &so)
{
    double b = st.top();
    st.pop();
    double a = st.top();
    st.pop();
    int op = so.top();
    so.pop();
    if(op == '+') a = a+b;
    else if(op == '-') a = a-b;
    else if(op == '*') a = a*b;
    else if(op == '/') a = a/b;
    st.push(a);
    return ;
}

int main()
{
    string s;
    while(getline(cin, s))
    {
        stack<double> st;
        stack<char> so;
        so.push('(');
        s += ')';
        bool nextIsOp = false;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i]=='(') {
                so.push('(');
            } else if(s[i]==')') {
                while(so.top() != '(') doCal(st, so);
                so.pop();
            } else if (nextIsOp) {
                while(cmp(so.top(), s[i])) doCal(st, so);
                so.push(s[i]);
                nextIsOp = false;
            } else {
                int j = i;
                if(s[j] == '-' || s[j] == '+') i++;
                while(mp.find(s[i]) == mp.npos) i++;
                string t = s.substr(j, i-j);
                st.push((double)stoi(t));
                i--;
                nextIsOp = true;
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}