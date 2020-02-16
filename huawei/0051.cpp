// 0051.输出单向链表中倒数第k个结点

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int a;
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            cin >> a;
            v.push_back(a);
        }
        cin >> a;
        cout << v[v.size()-a] << endl;
    }
    return 0;
}
