// 0048.从单向链表中删除指定值的节点

#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n, m, head, a, b;
    while(cin >> n)
    {
        map<int, int> list;
        cin >> head;
        list[head] = -1;
        for(int i = 0; i < n-1; i++)
        {
            cin >> a >> b;
            if(list[b] == -1) {
                list[b] = a;
                list[a] = -1;
            } else {
                list[a] = list[b];
                list[b] = a;
            }
        }
        cin >> m;
        for(a = head; a != -1; a = list[a])
            if (a != m) cout << a << ' ';
        cout << endl;
    }
    return 0;
}