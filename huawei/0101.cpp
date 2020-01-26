/* 输入整型数组和排序标识，对其元素按照升序或降序进行排序（一组测试用例可能会有多组数据） */

#include <iostream>
#include <algorithm>
using namespace std;

void mysort(int num[], int len, bool f)
{
    sort(num, num+len);
    if (f) {
        reverse(num, num+len);
    }
}

int main()
{
    int num[10000], n, f;
    while (cin >> n) 
    {
        for(int i = 0; i < n; i++)
        {
            cin >> num[i];
        }
        cin >> f;
        mysort(num, n, f);
        for(int i = 0; i < n; i++)
        {
            cout << num[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}