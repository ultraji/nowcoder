// 0080.整形数组合并

#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n, m, t;
    while(cin >> n)
    {
        set<int> st;
        while(n--)
        {
            cin >> t;
            st.insert(t);
        }
        cin >> m;
        while(m--)
        {
            cin >> t;
            st.insert(t);
        }
        for(auto it = st.begin(); it != st.end(); it++)
        {
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}
