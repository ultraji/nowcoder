// 0077.火车进站
// keywords: 堆栈

#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

vector<string> v;

void print_queue(queue<int> q)
{
    string s;
    while ( !q.empty() )
    {
        s += to_string(q.front());
        s += ' ';
        q.pop();
    }
    v.push_back(s);
}

void func(queue<int> in, stack<int> st, queue<int> r, bool doPush)
{
    if ( in.empty() ) {   // 结束条件
        if (doPush) return; // 入栈队列空了，再push不合理
        while ( !st.empty() )
        {
            r.push(st.top());
            st.pop();
        }
        print_queue(r);
        return ;
    } else {
        if (doPush) {   // 入栈
            st.push(in.front());
            in.pop();
        } else {        // 出栈 
            if (st.empty()) return ;// 栈是空，直接返回
            r.push(st.top());
            st.pop();
        }

        func(in, st, r, false);
        func(in, st, r, true);
    }
}

int main()
{
    int n, num;
    while(cin >> n)
    {
        v.clear();
        queue<int> q, r;
        stack<int> st;
        for(int i = 0; i < n; i++) 
        {
            cin >> num;
            q.push(num);
        }
        func(q, st, r, true);
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i] << endl;
        }
    }
    return 0;
}